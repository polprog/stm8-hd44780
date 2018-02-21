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

/* REDEFINABLE */
/* Port register definitions */
/* Data direction register */
#ifndef LCD_PORT_DDR
#define LCD_PORT_DDR PD_DDR
#endif
/* Control register 1 */
#ifndef LCD_PORT_CR1
#define LCD_PORT_CR1 PD_CR1
#endif
/* Output data register */
#ifndef LCD_PORT_ODR
#define LCD_PORT_ODR PD_ODR
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

/* NON REDEFINABLE */
/* General */
#define LCD_PORT_DATAMASK ((1<<LCD_PORT_E) | (1<<LCD_PORT_RS) | (0x0F << LCD_PORT_D))
#define LCD_CMD 0
#define LCD_DATA 1

/* Clear display */
#define LCD_CLR 0x01

/* Cursor home */
#define LCD_HOME 0x02

/* Entry mode set */
#define LCD_EMS 0x04
#define LCD_INC 0x02

/* Display ON/OFF control */
#define LCD_CTL 0x08
#define LCD_ON 0x04
#define LCD_OFF 0x00
#define LCD_CUR_ON 0x02
#define LCD_CUR_OFF 0x00
#define LCD_CUR_BLNK 0x01
#define LCD_CUR_NBLNK 0x00

/* Cursor or display shitft */

#define LCD_CURDISP 0x10
#define LCD_SHIFT_CUR 0x80
#define LCD_SHIFT 0x00
#define LCD_SHIFT_R 0x40
#define LCD_SHIFT_L 0x00

/* DDRAM set */
#define LCD_DDRAM_SET 0x80
#define LCD_LINE2 0x40

void lcd_gpioinit(void);

void lcd_send_byte(uint8_t b, uint8_t cmd);


void lcd_init();

void lcd_puts(uint8_t *c);

void lcd_setpos(uint8_t l, uint8_t c);
#endif
