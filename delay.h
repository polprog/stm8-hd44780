/* 
 * Based on delay.h by Oleg Terentiev 
 * Hand tuned delay functions by polprog
 */

#ifndef _DELAY_H_
#define _DELAY_H_

/*CPU freq in KHZ */
#ifndef F_CPU_K
#warning F_CPU_K not defined!
#endif

#define T_COUNT(x) (((( F_CPU_K * x) / 13333)-5)/3)
#define _delay_us( __us ) _delay_cycl( (uint16_t) ( T_COUNT(__us) ) )


static inline void _delay_cycl( uint16_t __ticks ){
  __asm__("nop\n nop\n");  
  do { __ticks--; } while ( __ticks );
  __asm__("nop\n"); 
}



inline void _delay_ms( uint16_t __ms ){
  while ( __ms-- ){
    _delay_us( 1000 );
  }
}

#endif

