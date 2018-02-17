#include <stdint.h>

#include <stm8s.h>




void trap_isr(void) __interrupt (0) {

}


void main(void){
  uint8_t i, j;


  /* external led on PB6 */
  PB_DDR |= (1<<6);
  PB_CR1 |= (1<<6);
  
  
  /* onboard led */
  PD_DDR |= (1<<0);
  PD_CR1 |= (1<<0);


  PB_ODR |= (0<<6);
 
  while(1){
    PD_ODR = ~PD_ODR;
    
    
    for(i = 0; i < 255; i++){
      for(j = 0; j < 255; j++){
      }
    }
  }
}
