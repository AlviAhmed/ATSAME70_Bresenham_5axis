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

void system_init(void)
{
	init_mcu();

	_pmc_enable_periph_clock(ID_PIOA);

	_pmc_enable_periph_clock(ID_PIOC);

	_pmc_enable_periph_clock(ID_PIOD);

	/* Disable Watchdog */
	hri_wdt_set_MR_WDDIS_bit(WDT);

	/* GPIO on PA2 */

	gpio_set_pin_level(xdir,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(xdir, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(xdir, GPIO_PIN_FUNCTION_OFF); 


	gpio_set_pin_level(xstep,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(xstep, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(xstep, GPIO_PIN_FUNCTION_OFF); 


	gpio_set_pin_level(ydir,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(ydir, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(ydir, GPIO_PIN_FUNCTION_OFF);


	gpio_set_pin_level(ystep,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(ystep, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(ystep, GPIO_PIN_FUNCTION_OFF); 

	gpio_set_pin_level(zdir,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(zdir, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(zdir, GPIO_PIN_FUNCTION_OFF);

	gpio_set_pin_level(zstep,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(zstep, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(zstep, GPIO_PIN_FUNCTION_OFF);
        
	gpio_set_pin_level(adir,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(adir, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(adir, GPIO_PIN_FUNCTION_OFF); 

	gpio_set_pin_level(astep,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(astep, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(astep, GPIO_PIN_FUNCTION_OFF);  

	gpio_set_pin_level(cdir,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(cdir, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(cdir, GPIO_PIN_FUNCTION_OFF);  

	gpio_set_pin_level(cstep,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(cstep, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(cstep, GPIO_PIN_FUNCTION_OFF); 

































}
