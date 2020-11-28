/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hpl_tc.h>
#define global_state false 

struct timer_descriptor TIMER_0;
/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	_pmc_enable_periph_clock(ID_TC0_CHANNEL0);
	timer_init(&TIMER_0, TC0, _tc_get_timer());
}

void system_init(void)
{
	init_mcu();

	_pmc_enable_periph_clock(ID_PIOC);

	/* Disable Watchdog */
	hri_wdt_set_MR_WDDIS_bit(WDT);

	gpio_set_pin_level(LED_D13,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <global_state"> High
	                   global_state);
	// Set pin direction to output
	gpio_set_pin_direction(LED_D13, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_D13, GPIO_PIN_FUNCTION_OFF); 

	gpio_set_pin_level(LED_D12,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <global_state"> High
	                   global_state);
	// Set pin direction to output
	gpio_set_pin_direction(LED_D12, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_D12, GPIO_PIN_FUNCTION_OFF); 

	gpio_set_pin_level(LED_D7,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <global_state"> High
	                   global_state);
	// Set pin direction to output
	gpio_set_pin_direction(LED_D7, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_D7, GPIO_PIN_FUNCTION_OFF); 



	gpio_set_pin_level(LED_D6,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <global_state"> High
	                   global_state);
	// Set pin direction to output
	gpio_set_pin_direction(LED_D6, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_D6, GPIO_PIN_FUNCTION_OFF); 

	gpio_set_pin_level(LED_D5,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <global_state"> High
	                   global_state);
	// Set pin direction to output
	gpio_set_pin_direction(LED_D5, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_D5, GPIO_PIN_FUNCTION_OFF);



	TIMER_0_init(); 

}
