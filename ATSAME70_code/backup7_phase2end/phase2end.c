//timer_fresh
#include "atmel_start.h"
#include <hal_gpio.h>
#include <hal_delay.h>  
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


//****************************************** Kinematics code 
#define driver_res 1 

#define N_Axis 5
#define steps_per_mm 800
#define steps_per_radian 127
#define motion_buffer_size 3
#define seq_length 20000 
#define low  false

typedef struct{
    uint8_t steps[N_Axis];   
    uint8_t step_sequence[seq_length]; 
    int  global_counter;
    bool direction[N_Axis];   
}motion_block_t;  

typedef struct{   //current absolute position in mm
  double x_pos; 
  double y_pos; 
  double z_pos; 
  double a_pos; 
  double c_pos; 
}curr_pos_struct;

volatile curr_pos_struct curr_pos;
volatile curr_pos_struct new_pos; 

volatile static motion_block_t motion_buffer[motion_buffer_size];  

volatile int motion_buffer_head; 

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


volatile int x_enable = 1;
volatile int y_enable = 1;
volatile int z_enable = 1;  

volatile int x_dir_enable = 0;
volatile int y_dir_enable = 0;
volatile int z_dir_enable = 0; 





volatile int block_release = 0;
volatile int seq_holder = 0;
volatile int seq_counter = 0; 

volatile int j = 0;

volatile int w = 0; 
volatile int counter = 0;
volatile int i = 0; 
volatile int general_counter = 0;
volatile int high = 1; 

volatile int placeholder = 0;

static int step_high = 5;
static int step_period = 10;

static void task0_cb(const struct timer_task *const timer_task) 
{         
  if (x_enable == 1){   
    gpio_set_pin_level(xstep, true);   
    x_enable = 0;
  }       
  else{ 
    gpio_set_pin_level(xstep, false);  
  } 

  if (y_enable == 1){ 
    gpio_set_pin_level(ystep, true);  
    y_enable = 0;
  }     
  else{ 
    gpio_set_pin_level(ystep, false);  
  } 

  if (z_enable == 1){ 
    gpio_set_pin_level(zstep, true);  
    z_enable = 0;
  }
  else{ 
    gpio_set_pin_level(zstep, false);  
  }

  timer_add_task(&TIMER_0, &task1);      

} 

static void task1_cb(const struct timer_task *const timer_task) {  
    gpio_set_pin_level(xstep, false);  
    gpio_set_pin_level(ystep, false);  
    gpio_set_pin_level(zstep, false);  


}


void func_led(){ 
   gpio_set_pin_level(LED0,false); 
   delay_ms(200);
   gpio_set_pin_level(LED0,true); 
   delay_ms(200);

}



#define total_num_blocks 3
int main(void)
{  

	atmel_start_init(); 
  gpio_set_pin_level(LED0, true); 
  delay_ms(1000);  
  
      task0.interval = step_period; 
      task0.cb = task0_cb; 
      task0.mode = TIMER_TASK_REPEAT;   

      task1.interval = step_high; 
      task1.cb = task1_cb; 
      task1.mode = TIMER_TASK_ONE_SHOT;    

      timer_add_task(&TIMER_0, &task0);      
      timer_start(&TIMER_0);      
      func_led();  

      curr_pos.x_pos = 0;  
      curr_pos.y_pos = 0;
      curr_pos.z_pos = 0; 
      curr_pos.a_pos = 0;
      curr_pos.c_pos = 0; 
      
      new_pos.x_pos = 0;  
      new_pos.y_pos = 0;
      new_pos.z_pos = 0; 
      new_pos.a_pos = 0;
      new_pos.c_pos = 0; 






volatile double jasons_input[total_num_blocks][3] = 
{
 {5,5,10},
 {5,5,0},
 {5,5,10} 
};


volatile double bresenham_input[total_num_blocks][3];


for (int i = 0; i < total_num_blocks; i ++){  
//  new_pos.x_pos = jasons_input[i][0];
//  new_pos.y_pos = jasons_input[i][1];
//  new_pos.z_pos = jasons_input[i][2]; 
  

  bresenham_input[i][0] = jasons_input[i][0] - curr_pos.x_pos;
  bresenham_input[i][1] = jasons_input[i][1] - curr_pos.y_pos;
  bresenham_input[i][2] = jasons_input[i][2] - curr_pos.z_pos; 

  curr_pos.x_pos = jasons_input[i][0];
  curr_pos.y_pos = jasons_input[i][1];
  curr_pos.z_pos = jasons_input[i][2]; 


}


 for (int index = 0; index < total_num_blocks; index ++) {       
   delay_ms(100);
   x_counter = (bresenham_input[index][0])*800; 
   y_counter = (bresenham_input[index][1])*800;   
   z_counter = (bresenham_input[index][2])*800;      

   int holder = 0; 
  int dx, dy, dz, da, dc, xs, ys, zs, as, cs, p1, p2, p3, err;  
  int x1 = 0; 
  int y1 = 0; 
  int z1 = 0;  
  int a1 = 0;
  int c1 = 0; 

  int x2 = x_counter; 
  int y2 = y_counter;
  int z2 = z_counter;  
  int a2 = 0; 
  int c2 = 0;   



  dx =  abs(x2-x1);
  dy =  abs(y2-y1);
  dz =  abs(z2-z1);   
  da =  abs(a2-a1);  
  dc =  abs(c2-c1);   

  if  (x2 > x1){  
    xs = 1;  
    motion_buffer[index].direction[0] = 1;
  }else{ 
    xs = -1; 
    motion_buffer[index].direction[0] = 0;
  }
  if  (y2 > y1){  
    ys = 1;
    motion_buffer[index].direction[1] = 1;
  }else{ 
    ys = -1; 
    motion_buffer[index].direction[1] = 0;
  } 

  if  (z2 > z1){  
    zs = 1; 
        motion_buffer[index].direction[2] = 1;
  }else{ 
    zs = -1;   
    motion_buffer[index].direction[2] = 0;
  }       


  // Driving the xaxis 
  if (dx >= dy && dx >= dz) 
  { 
    /* x2 - x1 is greater than both y2 - y1 and z2 - z1, then is the axis that is doing most of the motion?*/ 
    p1 = 2 * dy - dx; 
    p2 = 2 * dz - dx;    

    while (x1 != x2) 
    {    
      x1 += xs;  //x toggle      
      holder = motion_buffer[index].global_counter ++;
      motion_buffer[index].step_sequence[holder] = 0;
      if (p1 >= 0) 
      { 
      y1 += ys;  //y toggle
      holder = motion_buffer[index].global_counter ++;
      motion_buffer[index].step_sequence[holder] = 1;
      p1 -= 2 * dx;
      }
      if (p2 >= 0) 
      { 
      z1 += zs; //z toggle 
      holder = motion_buffer[index].global_counter ++;
      motion_buffer[index].step_sequence[holder] = 2;
      p2 -= 2 * dx; 
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
      y1 += ys;   // y toggle 
      holder = motion_buffer[index].global_counter ++;
      motion_buffer[index].step_sequence[holder] = 1;
      if (p1 >= 0) 
      { 
        x1 += xs;  // x toggle 
      holder = motion_buffer[index].global_counter ++;
      motion_buffer[index].step_sequence[holder] = 0;
        p1 -= 2 * dy;  
      } 
      if (p2 >= 0) 
      { 
        z1 += zs; //z toggle  
        holder = motion_buffer[index].global_counter ++;
        motion_buffer[index].step_sequence[holder] = 2;
        p2 -= 2 * dy; 
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
     z1 += zs;  // z toggle  
     holder = motion_buffer[index].global_counter ++;
     motion_buffer[index].step_sequence[holder] = 2;
     if (p1 >= 0) 
     { 
     y1 += ys;  // y toggle  
     holder = motion_buffer[index].global_counter ++;
     motion_buffer[index].step_sequence[holder] = 1;
     p1 -= 2 * dz; 
     }
     if (p2 >= 0) 
     {  
     x1 += xs;  // x toggle 
     holder = motion_buffer[index].global_counter ++;
     motion_buffer[index].step_sequence[holder] = 0;
     p2 -= 2 * dz; 
     }
     p1 += 2 * dy;
     p2 += 2 * dx; 
    }   
    }  

  }   //main bresenham code 

      func_led();

for (int w = 0; w < total_num_blocks; w ++){     
  int seq_holder = motion_buffer[w].global_counter; // getting the count of sequence in each block   

  for (int i = 0; i < seq_holder; i ++){   
    if (motion_buffer[w].step_sequence[i] == 0){        

//**************************************** direction logic
     if (motion_buffer[w].direction[0] == 0) {  //if xdir 0
       gpio_set_pin_level(xdir,false); 

     } 
     else if (motion_buffer[w].direction[0] == 1){  //if xdir 1
       gpio_set_pin_level(xdir,true);
     }   
//**************************************** ****************************************

      x_enable = 1;   
      while(x_enable == 1){} 
    }
    if (motion_buffer[w].step_sequence[i] == 1){    

      
//**************************************** direction logic
     if (motion_buffer[w].direction[1] == 0) {  //if ydir 0
       gpio_set_pin_level(ydir,false); 

     } 
     else if (motion_buffer[w].direction[1] == 1){  //if ydir 1
       gpio_set_pin_level(ydir,true);
     }   
//**************************************** ****************************************


      y_enable = 1;  
      while(y_enable == 1){} 

    } 

    if (motion_buffer[w].step_sequence[i] == 2){   
     
      
//**************************************** direction logic
     if (motion_buffer[w].direction[2] == 0) {  //if ydir 0
       gpio_set_pin_level(zdir,false); 

     } 
     else if (motion_buffer[w].direction[2] == 1){  //if ydir 1
       gpio_set_pin_level(zdir,true);
     }   
//**************************************** ****************************************
      
      z_enable = 1; 
      while(z_enable == 1){}
    }
   

  } 
//  delay_ms(100); 
func_led();
} //uses the data calculated by the buffer, outputs as steps

while(1){  

}


}



