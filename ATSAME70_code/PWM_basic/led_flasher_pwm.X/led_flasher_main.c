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


//void PWM_0_example (void){ 
//  pwm_set_parameters(&PWM_0,10000,5000);
//}

int main(void)
{
	atmel_start_init(); 
        int period = 100; 
        int eightbit = 1;
        int dutycycle_per=  eightbit / 255; 
        int dutycycle = 100 * dutycycle_per; 
          pwm_set_parameters(&PWM_0,100,1); 
          pwm_enable(&PWM_0);     //PD22, D13
	while (1) {  
          int i = 1;
          for (i = 1; i <= 100; i++){ 
            delay_ms(100); 
            pwm_set_parameters(&PWM_0,100,i);   
//          pwm_enable(&PWM_0);      //don't need the pwm enable 
            i += 9;
          }  
          int y = 100;
          for (y = 100; y > 1; y--){ 
            delay_ms(100); 
            pwm_set_parameters(&PWM_0,100,y);   
//          pwm_enable(&PWM_0);      //don't need the pwm enable 
            y -= 9;
          } 

	} 
        
}
