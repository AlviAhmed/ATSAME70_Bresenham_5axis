/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAME70 has 4 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3

#define xdir GPIO(GPIO_PORTA, 2) 
#define xstep GPIO(GPIO_PORTC, 19)  

#define ydir GPIO(GPIO_PORTD, 11) 
#define ystep GPIO(GPIO_PORTD, 27)  

#define zdir GPIO(GPIO_PORTA, 6) 
#define zstep GPIO(GPIO_PORTA, 5) 

#define adir GPIO(GPIO_PORTC, 9)
#define astep GPIO(GPIO_PORTA, 17) 

#define cdir GPIO(GPIO_PORTD, 22)
#define cstep GPIO(GPIO_PORTD, 20)

#endif // ATMEL_START_PINS_H_INCLUDED
