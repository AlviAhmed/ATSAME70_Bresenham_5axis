
/*  

********** X axis
D7 -> dir 
D6 -> step
********** 

********** Y axis
D5 -> dir 

D4 -> step
********** 

********** Z axis
D3 -> dir 
D2 -> step
**********

*/ 


/* 
THIS EDIT SHOULD ONLY BE VIEWABLE IN ALVI BRANCH
*/
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
#include <stdbool.h> 
#include <stdio.h>


#define xdir LED_D7 
#define xstep LED_D6 
#define ydir LED_D5 
#define ystep LED_D4 
#define zdir LED_D3  
#define zstep LED_D2  


//void SysTick_Handler(void); 
//pmc_enable_periph_clk(ID_TC0)
/* Defining a bunch of booleans */ 
volatile bool xbool = false; // boolean for enabling and disabling the x-axis
volatile int xcount = 0; // keeps count of x-axis steps
volatile bool ybool = false; // boolean for enabling and disabling the y-axis
volatile int ycount = 0; // keeps count of y-axis steps 
volatile bool zbool = false; 
volatile int zcount = 0;    

volatile int sys_count = 0;


/* Variables for storing the function data */ 
volatile int speed = 0; 
volatile int global_counter = 0; 
volatile int i = 0;  
/******************************************/ 

void step_control(int axis, int stepper, int direction );   

void xaxis (int dir, int steps);
void yaxis (int dir, int steps);
void zaxis (int dir, int steps);     
void ret_vol();//resetting all volatiles 



volatile uint32_t msTicks = 0;
  
void SysTick_Handler(void){ 
  msTicks++;
}

int main(void)
{   
//  PMC->PMC_PCER0 = 1<<ID_PIOA; //enable clock 
//  NVIC_EnableIRQ((IRQn_Type)SysTick_IRQn);  //don't really need if all I am doing is Systick
  u_int32_t returnCode;  
  returnCode  = SysTick_Config(SystemCoreClock / 1000);  //lower the divider, the slower the interrupt and vice versa
  if (returnCode != 0)  {                                   /* Check return code for errors */
    // Error Handling 
  }
  atmel_start_init(); 
  // x = 0 
  // y = 1
  // z = 2  
  int axis[] = {0,1,2,0,1,2};  
  int direction[] = {1,1,1,0,0,0}; 
  int steps[] = {100,100,100,100,100,100};   
  int size = sizeof(steps)/sizeof(steps[0]); //getting size of array
  //speed = 100; //just the value of the delay
  int num_com = 3;  
  while (1) {      
    for (i; i < size; i ++){   //by default will run through the various arrays for step, direction and axis
      step_control(axis[i], steps[i], direction[i]);
    }     
    delay_ms(10);
    glob_low(); //setting all the direction pins low once the for loop is done
    
  }
} 
void step_control (int axis, int stepper, int direction){  
  global_counter = 0; //making the counter 0 by default when engaging the axis
  switch (axis){ 
  case 0:   //enabling x-axis    
    if (direction == 0){   
      gpio_set_pin_level(LED_D7, false); //setting direction pin 0
    }else{ 
      gpio_set_pin_level(LED_D7, true); //else if dir == 1, true 
    } 
    xaxis(direction, stepper);
    break;
  case 1:   
    if (direction == 0){   
      gpio_set_pin_level(LED_D5, false); //setting direction pin 0
    }else{ 
      gpio_set_pin_level(LED_D5, true); //else if dir == 1, true
    } 
    yaxis(direction, stepper);
    break;
  case 2:   
    if (direction == 0){   
      gpio_set_pin_level(LED_D3, false); //setting direction pin 0
    }else{ 
      gpio_set_pin_level(LED_D3, true); //else if dir == 1, true
    } 
    zaxis(direction, stepper);
    break;
  } 
}  

void xaxis (int dir, int steps){   
  while (global_counter < steps){  
    if (msTicks == 1000){  
    	gpio_toggle_pin_level(LED_D6);  
        msTicks = 0;  
        global_counter++;  //only increment the global counter when toggles
        if (global_counter > steps){  
          ret_vol();
          break;
        }
    }
  }
} 

void yaxis (int dir, int steps){  
  while (global_counter < steps){  
    if (msTicks == 1000){  
    	gpio_toggle_pin_level(LED_D4);  
        msTicks = 0;  
        global_counter++;  //only increment the global counter when toggles
        if (global_counter > steps){  
          ret_vol();
          break;
        }
    }
  }

}

void zaxis (int dir, int steps){  
   while (global_counter < steps){  
    if (msTicks == 1000){  
    	gpio_toggle_pin_level(LED_D2);  
        msTicks = 0;  
        global_counter++;  //only increment the global counter when toggles
        if (global_counter > steps){  
          ret_vol();
          break;
        }
    }
  }
 
}    
void glob_low(){ 
  gpio_set_pin_level(LED_D7, false); //setting direction pin 0
  gpio_set_pin_level(LED_D5, false); //setting direction pin 0
  gpio_set_pin_level(LED_D3, false); //setting direction pin 0
} 


void ret_vol(){ //resetting all volatiles
  global_counter = 0; 
  msTicks = 0;  
}

