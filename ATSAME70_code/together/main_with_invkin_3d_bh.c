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


volatile int x_tog = 0; 
volatile int y_tog = 0; 

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

volatile int  xglob_cout;
volatile int  yglob_cout;
volatile int  zglob_cout;

volatile int index = 0; 
volatile int num_com = 0; 
volatile int bh_enable = 0;
static void task0_cb(const struct timer_task *const timer_task) 
{                

  if (x_enable == 1){ 
    gpio_toggle_pin_level(xstep);     
    x_enable = 0; 
  }  
  if (y_enable == 1){ 
    gpio_toggle_pin_level(ystep);    
    y_enable = 0;
  }  
  if (z_enable == 1){ 
    gpio_toggle_pin_level(zstep);   
    z_enable = 0;
  }  

} 

volatile  int axis_selector = 0;  
volatile  int block_index = 0; 

void plotLine (int x0, int y0, int x1, int y1); 

int main(void)
{  

	atmel_start_init(); 
      task0.interval = 100; 
      task0.cb = task0_cb; 
      task0.mode = TIMER_TASK_REPEAT; 
      timer_add_task(&TIMER_0, &task0);     
      timer_start(&TIMER_0);   


//****************************************** Kinematics code  
volatile double input_stream[total_num_blocks][3] = 
      { 
       {1,0,0}, 
       {0,1,0},
       {0,0,1},
       {5,2,70},
       {1,20,3},
       {60,8,4},
      };  
//****************************************** Kinematics code    
 for (int y = 0; y < total_num_blocks; y ++) {   

   x_counter = (input_stream[y][0])*10; 
   y_counter = (input_stream[y][1])*10;   
   z_counter = (input_stream[y][2])*10;     

  int dx, dy, dz, xs, ys, zs, p1, p2;  
  int x1 = 0; 
  int y1 = 0; 
  int z1 = 0; 
  int x2 = x_counter;
  int y2 = y_counter;
  int z2 = z_counter; 

  dx =  abs(x2-x1);
  dy =  abs(y2-y1);
  dz =  abs(z2-z1);  

  if  (x2 > x1){  
    xs = 1;
  }else{ 
    xs = -1;
  }
  if  (y2 > y1){  
    ys = 1;
  }else{ 
    ys = -1;
  }
  if  (z2 > z1){  
    zs = 1;
  }else{ 
    zs = -1;
  }     

  // Driving the xaxis 
  if (dx >= dy && dx >= dz) 
  { 
    /* x2 - x1 is greater than both y2 - y1 and z2 - z1, then is the axis that is doing most of the motion?*/ 
    p1 = 2 * dy - dx; 
    p2 = 2 * dz - dx;    

    while (x1 != x2) 
    {     
      
      x1 += xs;  //xtoggle  
      x_enable = 1; 
      while (x_enable == 1){}
      if (p1 >= 0) 
      { 
        y1 += ys; //ytoggle 
        p1 -= 2 * dx;
        y_enable = 1; 
       while (y_enable == 1){}
      }
      if (p2 >= 0) 
      { 
        z1 += zs; //ztoggle 
        p2 -= 2 * dx; 
        z_enable = 1;
        while (z_enable == 1){}
      }
      p1 += 2 * dy; 
      p2 += 2 * dz;  
      
    } 
  }  
  // Driving the y axis
  else if (dy >= dx && dy >= dz) 
  {    
    p1 = 2 * dx - dy; 
    p2 = 2 * dz - dy;   
    while (y1 != y2) 
    {  
      y1 += ys;   //ytoggle
      y_enable = 1; 
      while (y_enable == 1 ){}
      if (p1 >= 0) 
      { 
        x1 += xs;  //xtoggle 
        p1 -= 2 * dy;  
        x_enable = 1;
        while (x_enable == 1){}
      } 
      if (p2 >= 0) 
      { 
        z1 += zs;  //ztoggle
        p2 -= 2 * dy;  
        z_enable = 1; 
        while (z_enable == 1){}
      } 
      p1 += 2 * dx; 
      p2 += 2 * dz;  

    } 
  }  

  // Driving the z axis
  else 
  {   
    p1 = 2 * dy - dz; 
    p2 = 2 * dx - dz;  
    while (z1 != z2) 
    {   
     z1 += zs;   //ztoggle
     z_enable = 1;
     while (z_enable == 1){}
     if (p1 >= 0) 
     { 
       y1 += ys;  //ytoggle 
       p1 -= 2 * dz; 
       y_enable = 1;
       while (y_enable == 1){}
     }
     if (p2 >= 0) 
     {  
       x1 += xs;  //xtoggle
       p2 -= 2 * dz; 
       x_enable = 1;
       while (x_enable == 1){}
     }
     p1 += 2 * dy;
     p2 += 2 * dx; 
     
    } 
  }  
   delay_ms(100);  
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

void plotLine3D(int x1, int y1, int z1, int x2, int y2, int z2){   

}
