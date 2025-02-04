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

#define LED_D7 GPIO(GPIO_PORTA, 2)
#define LED_D2 GPIO(GPIO_PORTA, 5)
#define LED_D3 GPIO(GPIO_PORTA, 6)
#define LED_D6 GPIO(GPIO_PORTC, 19)
#define LED_D5 GPIO(GPIO_PORTD, 11)
#define LED_D4 GPIO(GPIO_PORTD, 27)

#endif // ATMEL_START_PINS_H_INCLUDED
