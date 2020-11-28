/**
 * \file
 *
 * \brief Application implement
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "atmel_start.h"
#include <hal_gpio.h>
#include <hal_delay.h>

static struct timer_task task0, task1;

static void task0_cb(const struct timer_task *const timer_task) 
{  
//  gpio_toggle_pin_level(xstep);   
  gpio_set_pin_level(xstep, true); 
  timer_add_task(&TIMER_0, &task1);  

} 

static void task1_cb(const struct timer_task *const timer_task) 
{   
//  gpio_toggle_pin_level(ystep);  
  gpio_set_pin_level(xstep, false); 
  timer_add_task(&TIMER_0, &task0); 
}
int main(void)
{
	atmel_start_init();

        task0.interval = 1000; //time in milli seconds
        task0.cb = task0_cb; 
        task0.mode = TIMER_TASK_ONE_SHOT; 

        task1.interval = 1000;  
        task1.cb = task1_cb; 
        task1.mode = TIMER_TASK_ONE_SHOT;

	timer_add_task(&TIMER_0, &task0); 

	timer_start(&TIMER_0);

	while (true) {  
	}
} 







