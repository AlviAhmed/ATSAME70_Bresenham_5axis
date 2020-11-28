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

/* Variables for storing the function data */ 
volatile int speed = 0;   
volatile int change_dir = 0;
volatile int global_counter = 0; 
volatile int i = 0;   
volatile int prevx = 0; 
volatile int prevy = 0; 
volatile int prevz = 0; 
volatile int current = 0;
/******************************************/ 


void step_control(int axis, int stepper, int direction );   

void xaxis (int dir, int steps);
void yaxis (int dir, int steps);
void zaxis (int dir, int steps);

int main(void)
{
  atmel_start_init();   
  //int axis[] = {3, 3 ,3,3};
  //int direction[] = {1,0,1,0}; 
  //int mm_measure[] = {10,10,10,10};      //in mm 

//  int steps[] = {3200,3200,3200,3200, 3200,3200,3200,3200, 3200,3200,3200,3200, 3200,3200,3200,3200};       

  int axis[] = {0,0,0,0 ,1,1,1,1 ,2,2,2,2, 3,3,3,3};   
  int direction[] = {1,0,1,0 ,1,0,1,0 ,1,0,1,0, 1,0,1,0}; 
  int mm_measure[] = {10,10,10,10, 10,10,10,10, 10,10,10,10, 10,10,10,10};      //in mm 
//  int ms_x[] = {1,2,4,8,16};
  int size = sizeof(mm_measure)/sizeof(mm_measure[0]); //getting size of array
  int num_com = 3;    
  int trial = 0;    

    delay_ms(1000);  

    gpio_set_pin_level(cdir, true); //else if dir == 1, true 
    delay_ms(1000); 
    gpio_set_pin_level(cdir, false); //else if dir == 1, true  


    delay_ms(1000);  


    gpio_set_pin_level(adir, true); //else if dir == 1, true 
    delay_ms(1000); 
    gpio_set_pin_level(adir, false); //else if dir == 1, true  
    delay_ms(1000);  

  while (1) {    
    speed = 50; //just the value of the delay  
    change_dir = 500;
    for (i; i < size; i ++){   //by default will run through the various arrays for step, direction and axis  
      //delay_ms(500);
      //config(ms_x[i]); 
      // 4mm = 1 rev = 3200 steps during the micro step 
      step_control(axis[i], mm_measure[i], direction[i]);  
    } 
  }
} 

void step_control (int axis, int millimeter, int direction){   
  int stepper = 800*millimeter; // 
  global_counter = 0; //making the counter 0 by default when engaging the axis   
  switch (axis){ 
  case 0:   //enabling x-axis   
    xaxis(direction, stepper * 2);
    break;
  case 1:  
    yaxis(direction, stepper * 2);
    break;
  case 2:  
    zaxis(direction, stepper * 2);
    break; 
  case 3:  
    xyaxis(direction, stepper * 2);  
    break; 
  case 4:  
    caxis(direction, stepper * 2);
    break;
  }   
}  

void xaxis (int dir, int steps){    
  if (dir != prevx){  
    delay_ms(change_dir);
  }
  if (dir == 0){    
    gpio_set_pin_level(xdir, false); 
  }else{ 
    gpio_set_pin_level(xdir, true); //else if dir == 1, true 
  }
  for (global_counter = 0; global_counter < steps; global_counter ++ ){ 
    delay_us(speed); 
    gpio_toggle_pin_level(xstep); //actually toggles the pin level
  } 
  prevx = dir;
} 

void yaxis (int dir, int steps){   
  if (dir != prevy){  
    delay_ms(change_dir);
  }
  if (dir == 0){   
    gpio_set_pin_level(ydir, false); //setting direction pin 0
  }else{ 
    gpio_set_pin_level(ydir, true); //else if dir == 1, true
  } 
  for (global_counter = 0; global_counter < steps; global_counter ++ ){ 
    delay_us(speed); 
    gpio_toggle_pin_level(ystep);
  } 
  prevy = dir;
}

void zaxis (int dir, int steps){   
  if (dir != prevz){  
    delay_ms(change_dir);
  }
  if (dir == 0){   
    gpio_set_pin_level(zdir, false); //setting direction pin 0
  }else{ 
    gpio_set_pin_level(zdir, true); //else if dir == 1, true
  } 
  for (global_counter = 0; global_counter < steps; global_counter ++ ){ 
    delay_us(speed); 
    gpio_toggle_pin_level(zstep);
  } 
  prevz = dir;
}  

void xyaxis (int dir, int steps){   
  if (dir != prevz){  
    delay_ms(change_dir);
  }
  if (dir == 0){   
    gpio_set_pin_level(xdir, false); //setting direction pin 0
    gpio_set_pin_level(ydir, false); //setting direction pin 0
  }else{ 
    gpio_set_pin_level(xdir, true); //else if dir == 1, true
    gpio_set_pin_level(ydir, true); //else if dir == 1, true
  } 
  for (global_counter = 0; global_counter < steps; global_counter ++ ){ 
    delay_us(speed); 
    gpio_toggle_pin_level(xstep);
    gpio_toggle_pin_level(ystep);
  } 
  prevz = dir;
} 

void aaxis (int dir, int steps){   // D9, D8
  if (dir == 0){   
    gpio_set_pin_level(adir, false); //setting direction pin 0
  }else{ 
    gpio_set_pin_level(adir, true); //else if dir == 1, true
  } 
  for (global_counter = 0; global_counter < steps; global_counter ++ ){ 
    delay_us(speed); 
    gpio_toggle_pin_level(astep);
  }
}

void caxis (int dir, int steps){   // D13, D12
  if (dir == 0){   
    gpio_set_pin_level(cdir, false); //setting direction pin 0
  }else{ 
    gpio_set_pin_level(cdir, true); //else if dir == 1, true
  } 
  for (global_counter = 0; global_counter < steps; global_counter ++ ){ 
    delay_us(speed); 
    gpio_toggle_pin_level(cstep);
  }
}
 
 
