

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define N_Axis 5
#define steps_per_mm 800
#define steps_per_radian 127
#define motion_buffer_size 256
#ifndef max
    #define max(a,b) (a>b ? a:b)
#endif

#ifndef M_PI
	#define M_PI 3.141592654
#endif

void delay();
double *inv_kin_slow();
void update_motion_buffer();

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
static int motion_buffer_head ;

typedef struct{
    uint32_t position[N_Axis];
    float direction[N_Axis];
    float prev_speed;
} pos_info_t;
static pos_info_t pos;

int main(int argc, char** argv) {
    double pose[5];
    double offset[] = {0,0,0};
    double joint_params[5];
    
    printf("Enter Pose: ");
	scanf("%lf %lf %lf %lf %lf",&pose[0],&pose[1],&pose[2],&pose[3],&pose[4]);
	printf("You Entered: %lf %lf %lf %lf %lf\n",pose[0],pose[1],pose[2],pose[3],pose[4]);
      
    inv_kin_slow(joint_params, pose, offset);
	printf("Inverse Kinematic Joint Parameters: %lf %lf %lf %lf %lf\n", joint_params[0],joint_params[1],joint_params[2],joint_params[3],joint_params[4]);
	
	update_motion_buffer(joint_params);
    

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

void update_motion_buffer(double* target){

    int i;
    uint32_t target_steps[N_Axis];
 
    motion_block_t *block = &motion_buffer[motion_buffer_head];
    block -> step_count = 0;
    block -> millimeters = 0;

    for(i=0;i<N_Axis;i++){
        if (i == 3 || i == 4){
            target_steps[i] = lround(target[i]*steps_per_radian) ; 
            block -> steps[i] = target_steps[i] - pos.position[i];
            block -> step_count = max(block->step_count,block->steps[i]);
            block -> radians += ((target_steps[i] - pos.position[i])/steps_per_radian)^2;
			if (i==3){
				printf("Steps A Motor: %d\n", block -> steps[i]);
			}
			if (i==4){
				printf("Steps C Motor: %d\n", block -> steps[i]);
			}
        }else{
            target_steps[i] = lround(target[i]*steps_per_mm) ; 
            block -> steps[i] = target_steps[i] - pos.position[i];
            block -> step_count = max(block->step_count,block->steps[i]);
            block -> millimeters += ((target_steps[i] - pos.position[i])/steps_per_mm)^2;
			if (i==0){
				printf("Steps X Motor: %d\n", block -> steps[i]);
			}
			if (i==1){
				printf("Steps Y Motor: %d\n",block -> steps[i]);
			}
			if (i==2){
				printf("Steps Z Motor: %d\n", block -> steps[i]);
			}
        }
    }
    block -> millimeters = sqrt(block->millimeters);
}

