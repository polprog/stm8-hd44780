/*
 * HD44780 LCD test/demo program for STM8
 * By Chris "polprog" Lasocki
 * 2018
 */
#include <stdint.h>
#include <stm8s.h>

#include "hd44780.h"
#include "delay.h"


void main(void){

  uint8_t a = 98;
  
  PB_DDR = 0xFF;
  PB_CR1 = 0xFF;


  lcd_gpioinit();
  lcd_init();
  lcd_send_byte(LCD_CTL | LCD_ON | LCD_CUR_ON | LCD_CUR_BLNK, LCD_CMD);
  
  lcd_puts("Hello from stm8");
  lcd_setpos(1, 0);
  lcd_puts(" to #avr <3 !");
  lcd_send_byte(LCD_CTL | LCD_ON | LCD_CUR_OFF, LCD_CMD);

  while(1);
}
