/* 
 * delay utilite for STM8 family
 * COSMIC and SDCC
 * Terentiev Oleg
 * t.oleg@ymail.com
 
 * modified so SDCC compiles it by polprog 
 */

#ifndef _UTIL_DELAY_H_
#define _UTIL_DELAY_H_ 1

#ifndef F_CPU
#warning F_CPU is not defined!
#endif

#define T_COUNT(x) ((( F_CPU * x / 1000000UL )-5)/5 )

/* 
 * Func delayed N cycles, where N = 3 + ( ticks * 3 )
 * so, ticks = ( N - 3 ) / 3, minimum delay is 6 CLK
 * when tick = 1, because 0 equels 65535
 */

static inline void _delay_cycl( unsigned short __ticks ){
  __asm__("nop\n nop\n");  
  do { __ticks--; } while ( __ticks );
  __asm__("nop\n"); 
}

static inline void _delay_us(unsigned short __us ){
  _delay_cycl( (unsigned short) (T_COUNT(__us)) );
}

static inline void _delay_ms( unsigned short __ms ){
  while ( __ms-- ){
    _delay_us( 1000 );
  }
}

#endif

