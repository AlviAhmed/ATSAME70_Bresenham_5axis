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
#define global_step GPIO(GPIO_PORTC, 19) 

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

volatile int period = 200; 

volatile int delay_num = 2000;

static void task0_cb(const struct timer_task *const timer_task) 
{            

  //if (x_enable == 1 && (x_counter < (x_stepper))){  
    gpio_toggle_pin_level(xstep);  
      //delay_ms(delay_num);   
      //period += 100;
//      if (period < 10000)  //less than signs first 
//      { 
//        period += 200;   //increment
//      } 
//      else 
//      {  
//        period -= 200;
//      } 
      //if (period > 10000){ 
      //  period = 200;
      //}
      //if (period > 10000){ 
      //  period = 200;
      //} 

          for (i = 1; i <= period; i++){  
            delay_ms(100);     
      timer_set_clock_cycles_per_tick(&TIMER_0, period);   
      //      _timer_set_period(&TIMER_0, i);  
            i += 100;
          }  
          int y = period;
          for (y = period; y > 1; y--){ 
            delay_ms(100);   
      timer_set_clock_cycles_per_tick(&TIMER_0, period);   
      //      _timer_set_period(&TIMER_0, y); 
            y -= 100;
          }    



  //else if (y_enable == 1 && (y_counter < (y_stepper))){  
 //   gpio_toggle_pin_level(ystep);  
   // y_counter++; 
 // } 
 // else if (z_enable == 1 && (z_counter < (z_stepper))){ 
  //  gpio_toggle_pin_level(zstep);  
  //  z_counter++; 
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
//   }  
} 

void step_control (int
                   axis, int millimeter, int direction){   
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
  int axis[] = {0 ,0 , 0 ,0};   
  int direction[] = {1,0,1,0}; 
  int mm_measure[] = {400, 400, 400, 400};      //in mm  
  int a = 0;
  int size = sizeof(mm_measure)/sizeof(mm_measure[0]); //getting size of array 

	atmel_start_init();

      task0.interval = 1; 
      task0.cb = task0_cb; 
      task0.mode = TIMER_TASK_REPEAT; 
      timer_add_task(&TIMER_0, &task0);     
      timer_start(&TIMER_0);     
      delay_ms(delay_num);  
        while (1){          
//          _timer_set_period(&TIMER_0, 10000); 
         // int i = 1;
         // for (i = 1; i <= period; i++){  
         //   delay_ms(100);     
         //   _timer_set_period(&TIMER_0, i);  
         //   timer_start(&TIMER_0);  
         //   i += 100;
         // }  
         // //int y = period;
         // //for (y = period; y > 1; y--){ 
         // //  delay_ms(100);   
         // //  _timer_set_period(&TIMER_0, y); 
         // //  timer_start(&TIMER_0);  
         // //  y -= 100;
         // //}    
         // i = 0; 
         // y = period;



          //_timer_set_period(&TIMER_0, 100); 
//          for (index; index < size;){  
//            step_control(axis[index], mm_measure[index], direction[index]);  
//          }  
//          index = 0;
        }
} 




