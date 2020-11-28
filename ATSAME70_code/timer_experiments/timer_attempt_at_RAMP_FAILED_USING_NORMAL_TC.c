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
#define driver_res 1
static struct timer_task task0, task1, task2; 


volatile int x_counter = 0; 
volatile int x_stepper = 0; 

volatile int y_counter = 0; 
volatile int y_stepper = 0; 

volatile int z_counter = 0; 
volatile int z_stepper = 0; 

volatile int x_dir = 0;
volatile int y_dir = 0;
volatile int z_dir = 0;

volatile int x_enable = 0;
volatile int y_enable = 0;
volatile int z_enable = 0;  

volatile int x_dir_enable = 0;
volatile int y_dir_enable = 0;
volatile int z_dir_enable = 0;


volatile int index = 0; 
volatile int num_com = 0;      

volatile int block = 0;
volatile int free = 10;
static void task0_cb(const struct timer_task *const timer_task) 
{               
  block ++;
  if (block >= free ){ 
    gpio_toggle_pin_level(xstep);   
    block = 0;  
  }
 // if (x_enable == 1 && (x_counter < (x_stepper))){ 
 //   gpio_toggle_pin_level(xstep);  
 //   x_counter++;  
 // }  
 // 
 // else if (y_enable == 1 && (y_counter < (y_stepper))){ 
 //   gpio_toggle_pin_level(ystep);  
 //   y_counter++; 
 // } 
 // else if (z_enable == 1 && (z_counter < (z_stepper))){ 
 //   gpio_toggle_pin_level(zstep);  
 //   z_counter++; 
 // } 
 // else{  
 //     x_enable = 0;  
 //     x_counter = 0; 
 //     x_stepper = 0;  

 //     y_enable = 0;  
 //     y_counter = 0; 
 //     y_stepper = 0; 

 //     z_enable = 0;  
 //     z_counter = 0; 
 //     z_stepper = 0;  

 //     index ++;
 //  }  
} 

void step_control (int axis, int millimeter, int direction){   
  int stepper = driver_res*millimeter; 
  if (axis == 0){   
    xaxis(direction, stepper*2);  
  } 
  else if (axis == 1){   
    yaxis(direction, stepper*2);  
  } 
  else if (axis == 2){   
    zaxis(direction, stepper*2);  
  } 
}   

void xaxis (int direction, int step){ 
  x_stepper = step;
  if (direction == 1){ 
      gpio_set_pin_level(xdir,true);
  }else{ 
      gpio_set_pin_level(xdir,false);
  }
  x_enable = 1; 
} 

void yaxis (int direction, int step){ 
  y_stepper = step;
  if (direction == 1){ 
      gpio_set_pin_level(ydir,true);
  }else{ 
      gpio_set_pin_level(ydir,false);
  }   
    y_enable = 1; 
}

void zaxis (int direction, int step){ 
  z_stepper = step;
  if (direction == 1){ 
      gpio_set_pin_level(zdir,true);
  }else{ 
      gpio_set_pin_level(zdir,false);
  }   
    z_enable = 1; 
} 

int main(void)
{ 
  int axis[] = {0};   
  int direction[] = {1}; 
  int mm_measure[] = {1000};      //in mm  
//  int axis[] = {0,0,0,0 ,1,1,1,1 ,2,2,2,2};   
//  int direction[] = {1,0,1,0 ,1,0,1,0 ,1,0,1,0}; 
//  int mm_measure[] = {10,10,10,10 ,10,10,10,10 ,10,10,10,10};      //in mm  

  int size = sizeof(mm_measure)/sizeof(mm_measure[0]); //getting size of array 

	atmel_start_init();  

      task0.interval = 1; //time in milli seconds
      task0.cb = task0_cb; 
      task0.mode = TIMER_TASK_REPEAT; 
      timer_add_task(&TIMER_0, &task0);     
      timer_start(&TIMER_0);  
        while (1){            
//          for (index; index < size;){  
//            step_control(axis[index], mm_measure[index], direction[index]);  
//          } 
        }
} 




