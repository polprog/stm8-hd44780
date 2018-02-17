#include <stdint.h>

#define PD_DDR (*(volatile uint8_t*)0x5011)
#define PD_CR1 (*(volatile uint8_t*)0x5012)
#define PD_ODR (*(volatile uint8_t*)0x500f)



void main(){
  uint8_t i, j;

  
  PD_DDR |= (1<<0);
  PD_CR1 |= (1<<0);
 
 
  while(1){
    PD_ODR = ~PD_ODR;

    
    for(i = 0; i < 255; i++){
      for(j = 0; j < 255; j++){
      }
    }
  }
}
