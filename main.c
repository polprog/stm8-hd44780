#include <stdint.h>

#include <stm8s.h>


#define F_CPU 16000000
#include "delay.h"







void main(void){
 


  /* external led on PB6 */
  PB_DDR |= (1<<6);
  PB_CR1 |= (1<<6);
  
  
  /* onboard led */
  PD_DDR |= (1<<0);
  PD_CR1 |= (1<<0);

  
  PB_ODR |= (1<<6);
 
  while(1){
    PD_ODR = ~PD_ODR;
    _delay_ms(10);
    PD_ODR = ~PD_ODR;
    _delay_ms(10);
    PD_ODR = ~PD_ODR;
    _delay_ms(10);
    PD_ODR = ~PD_ODR;
    _delay_ms(10);
    PD_ODR = ~PD_ODR;
    _delay_ms(10);
    PD_ODR = ~PD_ODR;
    _delay_ms(10);PD_ODR = ~PD_ODR;
    _delay_ms(10);
    PD_ODR = ~PD_ODR;
    _delay_ms(10);
    PD_ODR = ~PD_ODR;
    _delay_ms(10);
    PD_ODR = ~PD_ODR;
    _delay_ms(10);
    
  }
}
