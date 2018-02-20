/*
 * HD44780 driver library for STM8 (sdcc)
 * Uses 4 bit mode
 *
 * MCU-LCD pinout (default, override with defines):
 * Px0 - RS
 * Px1 - E
 * Px2-5 - D4-D7
 * where x is defined by LCD_PORT_*, by default PORTD
 * RS, E can be freely assigned in range of the same port
 * D4-D7 must be 4 consecutive pins (D4 is LSb of all 4)
 * Redefine D4-D7 by defining D4 pin bit number
 *
 * By Chris "polprog" Lasocki
 * 2018
 */


#ifndef _HD44780_H
#define _HD44780_H

#include <stdint.h>

/* Port register definitions */
/* Data direction register */
#ifndef LCD_PORT_DDR
#define LCD_PORT_DDR PD_DDR
#endif
/* Control register 1 */
#ifndef LCD_PORT_CR1
#define LCD_PORT_DDR PD_CR1
#endif
/* Output data register */
#ifndef LCD_PORT_ODR
#define LCD_PORT_DDR PD_ODR
#endif
/* Enable pin */
#ifndef LCD_PORT_E
#define LCD_PORT_E 0
#endif
/* RS pin */
#ifndef LCD_PORT_RS
#define LCD_PORT_RS 1
#endif
/* Data pin 4 (first data pin, D5 = this + 1)*/
#ifndef LCD_PORT_D
#define LCD_PORT_D 2
#endif



void lcd_gpioinit(void);

void lcd_send_byte(uint8_t b);


//void init();

//void putchar(uint8_t c);

//void clear();

//void home();


#endif
