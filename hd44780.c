#include <stm8s.h>
#include "hd44780.h"
#include "delay.h"

void lcd_gpioinit(void){
  LCD_PORT_DDR |= LCD_PORT_DATAMASK; //set all used pins as output
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //keep E high
  LCD_PORT_CR1 |= LCD_PORT_DATAMASK; //slow push pull output
}

/*
 * Send data/command byte
 * b - data bit
 * cmd - command (0) / data (1)
 */
void lcd_send_byte(uint8_t b, uint8_t cmd){
  LCD_PORT_ODR &= ~( LCD_PORT_DATAMASK & ~(1<<LCD_PORT_E) ); //all bits off
  
  
  LCD_PORT_ODR |= (cmd << LCD_PORT_RS); //command or data?
  
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //E up
  _delay_ms(10);
  LCD_PORT_ODR |= ( (b>>4) << LCD_PORT_D); //send data bit (MS nibble)
  _delay_ms(10);
  LCD_PORT_ODR &= ~(1<<LCD_PORT_E); //E down
  _delay_ms(10);
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //E up
  _delay_ms(10);
  LCD_PORT_ODR &= ~(0x0F << LCD_PORT_D);
  LCD_PORT_ODR |= ( (b & 0x0F) << LCD_PORT_D); //send data bit (LS nibble)
  _delay_ms(10);
  LCD_PORT_ODR &= ~(1<<LCD_PORT_E); //E down
  _delay_ms(10);
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
  while(*c != 0){
    lcd_send_byte(*c, LCD_DATA);
    c++;
  }
}
