#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define N_Axis 5
#define steps_per_mm 800
#define steps_per_radian 127
#define total_num_blocks 6
#define motion_buffer_size 256
#ifndef max
    #define max(a,b) (a>b ? a:b)
#endif

#ifndef M_PI
	#define M_PI 3.141592654
#endif

typedef struct{
    uint32_t steps[N_Axis]; 
// steps[0 -> xaxis] = #number of steps for this respective axis
// steps[1 -> yaxis] = #number of steps for this respective axis
// steps[2 -> zaxis] = #number of steps for this respective axis
// steps[3 -> axis] = #number of steps for this respective axis
// steps[4 -> caxis]  = #number of steps for this respective axis
    uint32_t step_count;
    float start_speed;
    float max_start_speed;
    float flat_speed;
    float acceleration;
    float millimeters;
    float radians;
}motion_block_t;

static motion_block_t motion_buffer[motion_buffer_size]; //array of motion buffer structures 
//each entrance in the array represents a block
static int motion_buffer_head;

typedef struct{
    uint32_t position[N_Axis];
    float direction[N_Axis];
    float prev_speed;
} pos_info_t;
static pos_info_t pos;    
// the only time that "pos" is used in the function update_motion_buffer(joint_params); 

void delay();
double *inv_kin_slow();
void update_motion_buffer();

int main(int argc, char** argv) { 
    double input_stream[total_num_blocks][5] = 
      { 
       {1,2,3,4,5}, 
       {4,5,6,7,6},
       {10,20,30,40,50},
       {45,54,62,78,60},
       {9,4,1,2,4},
       {7,8,8,8,8},
      }; 
// each row will represent a block 
// input_stream will represent a segment
    double pose[5]; 
    int i = 0; 
    //BECAREFUL, THE PROGRAM IS ASSUMING THE OFFSET 
    double offset[] = {0,0,0}; 
    //NORMALLY YOU WOULD HAVE TOO PUT IN THE CURRENT POSITION 
    //JASON SAYS THAT HE WILL TAKE CARE OF THAT FOR YOU
    double joint_params[5]; 
    do 
    { 
    printf("Enter Pose: ");  

    for (i = 0; i < 5; i ++){ 
      pose[i] = input_stream[motion_buffer_head][i]; //will increment through the blocks as motion buffer increments
    }
    printf("You Entered: %lf %lf %lf %lf %lf\n",pose[0],pose[1],pose[2],pose[3],pose[4]);
      
    inv_kin_slow(joint_params, pose, offset); //inputting joint_params array, pose array and offset array 
    //returns modified versions of these arrays that can be used for generating the steps 

	printf("Inverse Kinematic Joint Parameters: %lf %lf %lf %lf %lf\n", joint_params[0],joint_params[1],joint_params[2],joint_params[3],joint_params[4]);
	
	update_motion_buffer(joint_params); //this one here calls the update_motion_buffer and inputs the params 

    } 
    while(motion_buffer_head < total_num_blocks); 

  printf("\n");
  printf("\n");
  printf("\n");  

  volatile  int axis_selector = 0; 
  volatile  int x_counter= 0; 
  volatile  int y_counter= 0; 
  volatile  int z_counter= 0; 
  volatile  int a_counter= 0; 
  volatile  int c_counter= 0; 

  volatile  int x_dir= 0; 
  volatile  int y_dir= 0; 
  volatile  int z_dir= 0; 
  volatile  int a_dir= 0; 
  volatile  int c_dir= 0; 

  
  for (int i = 0; i < total_num_blocks; i++){         
    axis_selector = 0; 
    printf("Block #: %d \n", i);
    while (axis_selector < N_Axis){   
      if (axis_selector==0){
        printf(" X Axis Steps: %d \n", motion_buffer[i].steps[axis_selector]);  
      }
      if (axis_selector==1){
        printf(" Y Axis Steps: %d \n",motion_buffer[i].steps[axis_selector]); 
      }
      if (axis_selector==2){
        printf(" Z Axis Steps: %d \n ", motion_buffer[i].steps[axis_selector]); 
      } 
      if (axis_selector==3){
        printf(" A Axis Steps: %d \n", motion_buffer[i].steps[axis_selector]);
      }
      if (axis_selector==4){
        printf(" C Axis Steps: %d \n \n", motion_buffer[i].steps[axis_selector]);
      } 
      axis_selector ++;
    } 
  }
int block_finished = 0;  

 for (int y = 0; y < total_num_blocks; y ++) 
 {    
   x_counter = motion_buffer[y].steps[0]; //taking absolute I don't want to deal with negative for know
   y_counter = motion_buffer[y].steps[1];
   z_counter = motion_buffer[y].steps[2];
   a_counter = motion_buffer[y].steps[3];
   c_counter = motion_buffer[y].steps[4]; 
   if (x_counter < 0) //if the steps is negative it means a negative direction
   { 
     x_counter = abs(motion_buffer[y].steps[0]); 
     x_dir = 0; //setting direction pin to low
   }  
   else 
   { 
     x_counter = motion_buffer[y].steps[0]; 
     x_dir = 1; //else if positive  num, then set high
   } 

   if (y_counter < 0) //if the steps is negative it means a negative direction
   { 
     y_counter = abs(motion_buffer[y].steps[0]); 
     y_dir = 0; //setting direction pin to low
   }  
   else 
   { 
     y_counter = motion_buffer[y].steps[0]; 
     y_dir = 1; //else if positive  num, then set high
   }
   if (z_counter < 0) //if the steps is negative it means a negative direction
   { 
     z_counter = abs(motion_buffer[y].steps[0]); 
     z_dir = 0; //setting direction pin to low
   }  
   else 
   { 
     z_counter = motion_buffer[y].steps[0]; 
     z_dir = 1; //else if positive  num, then set high
   }
   if (a_counter < 0) //if the steps is negative it means a negative direction
   { 
     a_counter = abs(motion_buffer[y].steps[0]); 
     a_dir = 0; //setting direction pin to low
   }  
   else 
   { 
     a_counter = motion_buffer[y].steps[0]; 
     a_dir = 1; //else if positive  num, then set high
   }
   if (c_counter < 0) //if the steps is negative it means a negative direction
   { 
     c_counter = abs(motion_buffer[y].steps[0]); 
     c_dir = 0; //setting direction pin to low
   }  
   else 
   { 
     c_counter = motion_buffer[y].steps[0]; 
     c_dir = 1; //else if positive  num, then set high
   }
   block_finished = 0;   

   int bresenhamx = 1;
   int bresenhamy = 1;
   int bresenhamz = 1;
   int bresenhama = 1;
   int bresenhamc = 1; 

   printf(" Block Number #: %d \n",y );
   while ((x_counter + y_counter + z_counter + a_counter + c_counter) > 0) 
   {        
     for (int x = 0; x < bresenhamx; x++ ){  
       if (x_counter > 0){ 
         printf("x"); 
         x_counter --;
       }
     }
     for (int y = 0; y < bresenhamy; y++ ){ 
       if (y_counter > 0){ 
         printf("y"); 
         y_counter --;
       }
     }
     for (int z = 0; z < bresenhamz; z++ ){ 
       if (z_counter > 0){ 
         printf("z"); 
         z_counter --;
       }
     }
     for (int a = 0; a < bresenhama; a++ ){ 
       if (a_counter > 0){ 
         printf("a"); 
         a_counter --;
       }
     }
     for (int c = 0; c < bresenhamc; c++ ){ 
       if (c_counter > 0){ 
         printf("c"); 
         c_counter --;
       }
     }
   } 
   printf("\n");


 }
    return (EXIT_SUCCESS);
}

void delay(){
    unsigned int i,j;
    for(i=0;i<1e5;i++){
        j++;
    }
}

double* inv_kin_slow(double *out, double *pose, double *offset){
 
    out[3] = acos(cos(pose[3])); 

    out[4] = atan2(sin(pose[4])*sin(pose[3]),cos(pose[4]*sin(pose[3])));
 
    out[0] = cos(pose[4])*(pose[0]-offset[0]) - sin(pose[4])*(pose[1]-offset[1]);
   
    out[1] = sin(pose[4])*cos(pose[3])*(pose[0]-offset[0]) +
        cos(pose[4])*sin(pose[3])*(pose[1]-offset[1]) - 
        sin(pose[3])*(pose[2]-offset[2]);

    out[2] = sin(pose[4])*sin(pose[3])*(pose[0]-offset[0]) +
        cos(pose[4])*sin(pose[3])*(pose[1]-offset[1]) - 
        cos(pose[3])*(pose[2]-offset[2]);
    
}


// *** update motion buffer function 





void update_motion_buffer(double* target){ //target is the joint array

    int i;
    uint32_t target_steps[N_Axis]; //n-axis = 5, allocating a new array with enough memory for 5 steps 
// the target_steps array is used to hold the current # steps in order to have the pos.position substracted from it, the difference will then be set to the blocks -> step_count
 
    motion_block_t *block = &motion_buffer[motion_buffer_head]; //new motion block poiner (named block)  = address of motionbuffer @ index 0  
    printf("Current motion head: %d \n \n", motion_buffer_head);
    // the motion buffer is the original struct array of type motion_block_t  
    // block is simply extracting 1 block from the motion_buffer array at the starting index (since Jason made this to run once) 


    block -> step_count = 0; //as values are being set to block since it is pointing to the address of motion_buffer at a certain index it is also changing the values at that index in the motion buffer 

    block -> millimeters = 0; //setting the millimeters to 0 initiallly

    for(i=0;i<N_Axis;i++){
        if (i == 3 || i == 4){ //I using difference math function (radians) since A and C axis are rotational and the X,Y,Z axis are more linear
            target_steps[i] = lround(target[i]*steps_per_radian) ; /* target steps is the array that was defined in the beginning of the code, target_steps[N_axis] where n-axis  = 5 
it is the target steps of each stepper*/ 

            block -> steps[i] = abs((target_steps[i] - pos.position[i])) / 1000; 
            /* The number of steps that will be assigned to struct variable steps[i] at the axis i will be the target steps at that axis substracted by the pos position*/ 

            /* Remeber that the pos is the instance of the structure pos_info_t*/ 

            //for now dividing by a 1000 since num too huge to print 

            block -> step_count = max(block->step_count,block->steps[i]); 
            printf(" Current step_count %d \n \n", block -> step_count);
            block -> radians += ((target_steps[i] - pos.position[i])/steps_per_radian)^2; 
            printf(" Current radians %lf \n \n", block -> radians);
			if (i==3){
				printf(" Steps A Motor: %d \n ", block -> steps[i]);
			}
			if (i==4){
				printf(" Steps C Motor: %d \n ", block -> steps[i]);
			}
        }else{
            target_steps[i] = lround(target[i]*steps_per_mm) ; 
            block -> steps[i] = abs((target_steps[i] - pos.position[i])) / 1000; 
            //for now dividing by a 1000 since num too huge to print
            block -> step_count = max(block->step_count,block->steps[i]);  
            printf(" \n \n");
            printf(" Current step_count: %d  ", block -> step_count);
            block -> millimeters += ((target_steps[i] - pos.position[i])/steps_per_mm)^2; 
            printf(" Current millimeters %lf \n ", block -> millimeters);
			if (i==0){
				printf(" Steps X Motor: %d \n", block -> steps[i]); 
			}
			if (i==1){
				printf(" Steps Y Motor: %d \n",block -> steps[i]); 
			}
			if (i==2){
				printf(" Steps Z Motor: %d \n \n ", block -> steps[i]); 
			}
        }
    }
    block -> millimeters = sqrt(block->millimeters); 
    /* Variables that this code used from the struct, 
     steps 
    step_count 
    radians 
    */ 
    /* Variables that are unused, will need to be used for ramps
    float start_speed;
    float max_start_speed;
    float flat_speed;
    float acceleration;
    */  
   motion_buffer_head ++;  //increment the motion buffer head so that next time the next index is updated
}

/*  */
