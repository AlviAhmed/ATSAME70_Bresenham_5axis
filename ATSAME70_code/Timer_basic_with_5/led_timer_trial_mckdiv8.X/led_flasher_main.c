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
static struct timer_task task1, task2, task3, task4, task5 ;

static void task1_cb(const struct timer_task *const timer_task) 
{ 
  gpio_toggle_pin_level(LED_D12); 
}

static void task2_cb(const struct timer_task *const timer_task)
{ 
  gpio_toggle_pin_level(LED_D13); 
}  

static void task3_cb(const struct timer_task *const timer_task)
{ 
  gpio_toggle_pin_level(LED_D7); 
}  

static void task4_cb(const struct timer_task *const timer_task)
{ 
  gpio_toggle_pin_level(LED_D6); 
}  

static void task5_cb(const struct timer_task *const timer_task)
{ 
  gpio_toggle_pin_level(LED_D5); 
} 

int main(void)
{
	atmel_start_init(); 
         task1.interval = 100;
         task1.cb       = task1_cb;
         task1.mode     = TIMER_TASK_REPEAT;  

         task2.interval = 200;
         task2.cb       = task2_cb;
         task2.mode     = TIMER_TASK_REPEAT;


         task3.interval = 300;
         task3.cb       = task3_cb;
         task3.mode     = TIMER_TASK_REPEAT;


         task4.interval = 400;
         task4.cb       = task4_cb;
         task4.mode     = TIMER_TASK_REPEAT;


         task5.interval = 500;
         task5.cb       = task5_cb;
         task5.mode     = TIMER_TASK_REPEAT;


         timer_add_task(&TIMER_0, &task1); 
         timer_add_task(&TIMER_0, &task2); 
         timer_add_task(&TIMER_0, &task3); 
         timer_add_task(&TIMER_0, &task4); 
         timer_add_task(&TIMER_0, &task5); 

         timer_start(&TIMER_0);  
	while (true) {  
	}
}
