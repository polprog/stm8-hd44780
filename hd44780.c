#include "hd44780.h"
#include "delay.h"

void lcd_gpioinit(void){
  LCD_PORT_DDR |= LCD_PORT_DATAMASK; //set all used pins as output
  LCD_PORT_CR1 |= LCD_PORT_DATAMASK; //slow push pull output
}

/*
 * Send data/command byte
 * b - data bit
 * cmd - command (1) / data (0)
 */
void lcd_send_byte(uint8_t b, uint8_t cmd){
  LCD_PORT_ODR &= ~LCD_PORT_DATAMASK; //all bits off
  
  
  LCD_PORT_ODR |= (cmd << LCD_PORT_RS); //command or data?
  
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //E up
  LCD_PORT_ODR |= ( (b>>4) << LCD_PORT_D); //send data bit (MS nibble)
  LCD_PORT_ODR &= ~(1<<LCD_PORT_E); //E down
  LCD_PORT_ODR |= (1<<LCD_PORT_E); //E up
  LCD_PORT_ODR |= ( (b & 0x0F) << LCD_PORT_D); //send data bit (LS nibble)
  LCD_PORT_ODR &= ~(1<<LCD_PORT_E); //E down
  
  
}
