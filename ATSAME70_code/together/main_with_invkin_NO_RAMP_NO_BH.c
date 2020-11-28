//timer_fresh
#include "atmel_start.h"
#include <hal_gpio.h>
#include <hal_delay.h>  
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <math.h> 


//****************************************** Kinematics code 
#define driver_res 1 

#define N_Axis 5
#define steps_per_mm 800
#define steps_per_radian 127
#define motion_buffer_size 256
#define total_num_blocks 6
#ifndef max
    #define max(a,b) (a>b ? a:b)
#endif
#ifndef M_PI
	#define M_PI 3.141592654
#endif  

typedef struct{
    uint32_t steps[N_Axis]; 
    uint32_t step_count;
    float start_speed;
    float max_start_speed;
    float flat_speed;
    float acceleration;
    float millimeters;
    float radians;
}motion_block_t; 
static motion_block_t motion_buffer[motion_buffer_size]; 
volatile int motion_buffer_head;
typedef struct{
    uint32_t position[N_Axis];
    float direction[N_Axis];
    float prev_speed;
} pos_info_t;
static pos_info_t pos;    
void delay();
double *inv_kin_slow();
void update_motion_buffer();


//****************************************** Kinematics code  


static struct timer_task task0, task1, task2; 

volatile int x_counter = 0; 
volatile int x_stepper = 0; 

volatile int y_counter = 0; 
volatile int y_stepper = 0; 

volatile int z_counter = 0; 
volatile int z_stepper = 0; 

volatile int a_counter = 0; 
volatile int a_stepper = 0; 

volatile int c_counter = 0; 
volatile int c_stepper = 0; 



volatile int x_dir = 0;
volatile int y_dir = 0;
volatile int z_dir = 0;

volatile int a_dir = 0;
volatile int c_dir = 0;

volatile int x_enable = 0;
volatile int y_enable = 0;
volatile int z_enable = 0;  

volatile int x_dir_enable = 0;
volatile int y_dir_enable = 0;
volatile int z_dir_enable = 0;

volatile int index = 0; 
volatile int num_com = 0; 

static void task0_cb(const struct timer_task *const timer_task) 
{            
  if (x_enable == 1){ 
    gpio_toggle_pin_level(xstep);   
    x_counter --;
    x_enable = 0;
  }  
  if (y_enable == 1){ 
    gpio_toggle_pin_level(ystep);   
    y_counter --;
    y_enable = 0;
  }  
  if (z_enable == 1){ 
    gpio_toggle_pin_level(zstep);   
   z_counter --;
    z_enable = 0;
  }  
} 

volatile  int axis_selector = 0;  
volatile  int block_index = 0; 



int main(void)
{  

  int axis[] = {0,1,2};   
  int direction[] = {0,0,0}; 
  int mm_measure[] = {400,400,400};      //in mm  

  int size = sizeof(mm_measure)/sizeof(mm_measure[0]); //getting size of array 
	atmel_start_init(); 
      task0.interval = 100; 
      task0.cb = task0_cb; 
      task0.mode = TIMER_TASK_REPEAT; 
      timer_add_task(&TIMER_0, &task0);     
      timer_start(&TIMER_0);   


//****************************************** Kinematics code  
    double input_stream[total_num_blocks][5] = 
      { 
       {2,1,3}, 
       {4,5,6},
       {1,2,3},
       {4,5,6},
       {9,4,1},
       {7,8,8},
      };  
//****************************************** Kinematics code   
 for (int y = 0; y < total_num_blocks; y ++) { 

   x_counter = (input_stream[y][0])*100; 
   y_counter = (input_stream[y][1])*100;
   z_counter = (input_stream[y][2])*100;

   int bresenhamx = 1;
   int bresenhamy = 1;
   int bresenhamz = 1;

   while ((x_counter + y_counter + z_counter) > 0) 
   {         
     
     for (int x = 0; x < bresenhamx; x++ ){  
       if(x_counter > 0){   
         x_enable = 1;   
       } 
     } 

     for (int y = 0; y < bresenhamy; y++ ){ 
       if (y_counter > 0){  
         y_enable = 1; 
       }
     }
     for (int z = 0; z < bresenhamz; z++ ){ 
       if (z_counter > 0){  
         z_enable = 1; 
       }
     } 
   }    
}
        while (1){         

        } //end of while (1)
}//end of main

//****************************************** Kinematics code 

void update_motion_buffer(double* target){ 
    int i;
    uint32_t target_steps[N_Axis]; 
    motion_block_t *block = &motion_buffer[motion_buffer_head];   
    block -> step_count = 0;  
    block -> millimeters = 0; 
    for(i=0;i<N_Axis;i++){
        if (i == 3 || i == 4){ 
            target_steps[i] = target[i];  
            //target_steps[i] = lround(target[i]*steps_per_radian);  
            block -> steps[i] = (target_steps[i] - pos.position[i]); 
            block -> step_count = max(block->step_count,block->steps[i]); 
            block -> radians += (target_steps[i] - pos.position[i]); 
        }else{
            target_steps[i] = target[i]*steps_per_mm; 
           // target_steps[i] = lround(target[i]*steps_per_mm) ; 
            block -> steps[i] = abs((target_steps[i] - pos.position[i])); 
            block -> step_count = max(block->step_count,block->steps[i]);  
        }
    }
//    block -> millimeters = sqrt(block->millimeters); 
   motion_buffer_head ++;  
}
//****************************************** Kinematics code 
