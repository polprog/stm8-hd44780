#include "hd44780.h"

void lcd_gpioinit(void){
  LCD_PORT_DDR |= 0x3F; //all 6 pins as output
  LCD_PORT_CR1 |= 0x3F; //slow push pull output
}


void lcd_send_byte(uint8_t b){
  LCD_PORT_
  
}
