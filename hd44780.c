/*
 * HD44780 driver library for STM8 (sdcc)
 * Uses 4 bit mode
 *
 * MCU-LCD pinout (default, override with defines):
 * Px0 - RS
 * Px1 - E
 * Px2-5 - D4-D7
 * where x is defined by LCD_PORT_*, by default PORTD
 * RS, E can be freely assigned in range of the same port
 * D4-D7 must be 4 consecutive pins (D4 is LSb of all 4)
 * Redefine D4-D7 by defining D4 pin bit number
 *
 * By Chris "polprog" Lasocki
 * 2018
 */


#include <stm8s.h>
#include "hd44780.h"
#include "delay.h"

void lcd_gpioinit(void){
  LCD_PORT_DDR |= LCD_PORT_DATAMASK; //set all used pins as output
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //keep E high
  LCD_PORT_CR1 |= LCD_PORT_DATAMASK; //slow push pull output
}


void lcd_send_byte(uint8_t b, uint8_t cmd){
  LCD_PORT_ODR &= ~( LCD_PORT_DATAMASK & ~(1<<LCD_PORT_E) ); //all bits off
  
  
  LCD_PORT_ODR |= (cmd << LCD_PORT_RS); //command or data?
  
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //E up
  LCD_PORT_ODR |= ( (b>>4) << LCD_PORT_D); //send data bit (MS nibble)
  LCD_PORT_ODR &= ~(1<<LCD_PORT_E); //E down
  _delay_ms(2);
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //E up
  LCD_PORT_ODR &= ~(0x0F << LCD_PORT_D);
  LCD_PORT_ODR |= ( (b & 0x0F) << LCD_PORT_D); //send data bit (LS nibble)
  LCD_PORT_ODR &= ~(1<<LCD_PORT_E); //E down
  _delay_ms(2);
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //E up
  
}

void lcd_init(){
  /* Make sure we are in 4 bit mode */
  lcd_send_byte(0x33, LCD_CMD);
  lcd_send_byte(0x32, LCD_CMD);

  /* Clear; Cursor Home */
  lcd_send_byte(0x01, LCD_CMD);
  lcd_send_byte(0x02, LCD_CMD);
}

/* Print a null terminated string (supports newlines as LF)*/
void lcd_puts(uint8_t *c){
  while(*c){
    lcd_send_byte(*c, LCD_DATA);
    c++;
  }
}

void lcd_setpos(uint8_t l, uint8_t c){
  lcd_send_byte(LCD_DDRAM_SET | c + (l * LCD_LINE2), LCD_CMD);
}
