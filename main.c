#include <stdint.h>

#include <stm8s.h>

<<<<<<< Updated upstream
#define F_CPU_K 1600L
#include "delay.h"

void main(void){
=======

#define F_CPU 16000000
#include "delay.h"







void main(void){
 


>>>>>>> Stashed changes
  /* external led on PB6 */
  PB_DDR |= (1<<6);
  PB_CR1 |= (1<<6);
  
  
  /* onboard led */
  PD_DDR |= (1<<0);
  PD_CR1 |= (1<<0);

  
  PB_ODR |= (1<<6);
 
  while(1){
    PD_ODR = ~PD_ODR;
<<<<<<< Updated upstream
    _delay_us(100);
    PD_ODR = ~PD_ODR;
    _delay_us(50);
=======
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
>>>>>>> Stashed changes
    
  }
}
