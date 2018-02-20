#include <stdint.h>

#include <stm8s.h>

#define F_CPU_K 1600L
#include "delay.h"

void main(void){
  /* external led on PB6 */
  PB_DDR |= (1<<6);
  PB_CR1 |= (1<<6);
  
  
  /* onboard led */
  PD_DDR |= (1<<0);
  PD_CR1 |= (1<<0);

  
  PB_ODR |= (0<<6);
 
  while(1){
    PD_ODR = ~PD_ODR;
    _delay_us(100);
    PD_ODR = ~PD_ODR;
    _delay_us(50);
    
  }
}
