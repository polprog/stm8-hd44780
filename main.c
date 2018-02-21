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
  lcd_send_byte(0x0F, LCD_CMD);
  
  //lcd_send_byte(0b00001111, LCD_CMD);
  //lcd_send_byte('a', LCD_DATA);
  lcd_puts("aada");
  return ;
  
  do {
    
    lcd_send_byte(a++, LCD_DATA);
    PB_ODR = ~PB_ODR;
    _delay_ms(100);
  }while (1);

  
  while(1){
    PD_ODR = ~PD_ODR;
    _delay_us(100);
    PD_ODR = ~PD_ODR;
    _delay_us(50);
  }
}
