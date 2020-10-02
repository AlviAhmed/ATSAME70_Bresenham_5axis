/* bresenham velocity with 5 axis*/ 

#include <stdio.h>
#include <stdlib.h>  
#include <stdint.h>

#define N_AXIS 5
#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2
#define A_AXIS 3
#define C_AXIS 4
#define max(a,b) (((a) > (b)) ? (a) : (b))

#define motion_buffer_size 5  


typedef struct{
    // Used for stepper control
    uint32_t steps[N_AXIS];
    uint32_t step_count;   

    /* Custom */
    uint32_t step_event_count; //largest step number in block 
    /* Custom */ 

    // Used for acceleration 
    /* Modified, used to other variables for speed here, took them out to make it simplier to test*/
    float flat_speed; 
    float ac_speed; //this is the speed that the ac axis will move 
    /* Since the a and c axis will move at different speed it is important to have a different speed setting for the ac axis*/
}motion_block_t;  



typedef struct  
{
    uint16_t n_step;          // Number of step events to be executed for this segment
    uint8_t st_block_index;   // Stepper block data index. Uses this information to execute this segment.
} segment_t; 

static segment_t segment_buffer[motion_buffer_size];  

// Stepper ISR data struct. Contains the running data for the main stepper ISR.
typedef struct  
{
    // Used by the bresenham line algorithm
    uint32_t counter_x,        // Counter variables for the bresenham line tracer
        counter_y, 
        counter_z, 
        counter_a, 
        counter_c;
    uint8_t execute_step;     // Flags step execution for each interrupt.
    uint8_t step_pulse_time;  // Step pulse reset time after step rise
    uint8_t step_outbits;         // The next stepping-bits to be output
    uint8_t dir_outbits;
    uint16_t step_count;       // Steps remaining in line segment motion  
    uint8_t exec_block_index; // Tracks the current st_block index. Change indicates new block.
    motion_block_t *exec_block;   // Pointer to the block data for the segment being executed
    segment_t *exec_segment;  // Pointer to the segment being executed
} stepper_t;  
static stepper_t st;  

volatile int arr[motion_buffer_size][N_AXIS] = 
{  
    {1,1,1,1,2}, 
    {1,1,1,2,3}, 
    {1,1,1,3,1}, 
    {3,5,7,4,5}, 
    {4,7,1,0,0}
};    

volatile float velarr[motion_buffer_size][1] = 
{ 
    {1.0},
    {2.0},
    {3.0},
    {4.0},
    {5.0}
}; 

volatile float acarr[motion_buffer_size][1] = 
{ 
    {0.5},
    {0.5},
    {0.5},
    {0.5},
    {0.5}
};




volatile int motion_buffer_head; 
static motion_block_t motion_buffer[motion_buffer_size];
volatile int init_enable = 1; 

int main()  
{ 
    printf("st.exec_segment is == NULL\n");
    int idx= 0;  
    int idy = 0;
    volatile motion_block_t *block = &motion_buffer[motion_buffer_head];    
    /* Begin: Filling up the motion_buffer array with test values*/ 
    /* block variable is equal to the address of the motion_buffer[motion_buffer_head], filling up the buffer by making block equal to values in the arr[][] */
    for (idy = 0; idy < motion_buffer_size; idy++)  // buffer index
    {  
/*every time a new indent, the block variable will act as a placeholder for the next index of the motion buffer */ 
/* Therefore can fill up to motion_buffer_size without having to have motion_buffer_size amount of block variables*/
        block = &motion_buffer[idy];  //here is where the block gets updated with a new instance of the motion buffer
        block->flat_speed = velarr[idy][0]; //filling up the velocity portion of the block  
        block->ac_speed = acarr[idy][0]; //filling up the velocity portion of the block  
        for (idx = 0; idx < N_AXIS; idx++)  //axis index
        {   
            block->steps[idx] = arr[idy][idx]; //instead of arr  
            block->step_event_count = max(block->step_event_count, block->steps[idx]);    
        } 
    }     
    /* End: Filling up the motion_buffer array with test values*/  
    /* This filled up motion buffer will be what Jason eventually sends me*/


    segment_t *prep_segment = &segment_buffer[motion_buffer_head]; 
    printf("Creating new segment struct \n");  
    printf("prep_segment buffer output \n");  
    prep_segment->st_block_index = motion_buffer_head; 
    for (idy = 0; idy < motion_buffer_size; idy++)  // buffer number
    {    
        for (idx = 0; idx < N_AXIS; idx++) 
        {
            prep_segment = &segment_buffer[idy]; 
            prep_segment->st_block_index = idy; 
            prep_segment->n_step += motion_buffer[prep_segment->st_block_index].steps[idx];
        } 
    }       
    while (1)  /* Simulates the ISR*/
    {   
        if (st.exec_segment == NULL)  
        {    
            
            st.exec_segment = &segment_buffer[motion_buffer_head];   
            st.step_count = ((st.exec_segment->n_step)); // NOTE: Can sometimes be zero when moving slow.   
            //if ( st.exec_block_index != st.exec_segment->st_block_index )  
            //{ 
            //                   printf("test \n");
            st.exec_block_index = st.exec_segment->st_block_index;
            st.exec_block = &motion_buffer[st.exec_block_index];
            // Initialize Bresenham line and distance counters 
            st.counter_x = st.counter_y = st.counter_z = st.counter_a = st.counter_c = (st.exec_block->step_event_count >> 1);     
            //}
            printf(" \n Starting New Block \n");
            // printf("\n Current Velocity: %f \n", st.exec_block->flat_speed);  
        }    
            
        st.counter_x += st.exec_block->steps[X_AXIS]; 
        if (st.counter_x > st.exec_block->step_event_count)  
        {
            printf(" X ");
            st.counter_x -= st.exec_block->step_event_count; 
            st.step_count--;
        }
        st.counter_y += st.exec_block->steps[Y_AXIS];
        if (st.counter_y > st.exec_block->step_event_count)  
        {
            printf(" Y ");
            st.counter_y -= st.exec_block->step_event_count; 
            st.step_count--;
        }
        st.counter_z += st.exec_block->steps[Z_AXIS];
        if (st.counter_z > st.exec_block->step_event_count)  
        {
            printf(" Z ");
            st.counter_z -= st.exec_block->step_event_count; 
            st.step_count--;
        }       
        printf("\n");
/************************************************** a and c axis ****/ 
        st.counter_a += st.exec_block->steps[A_AXIS];
        if (st.counter_a > st.exec_block->step_event_count)  
        {
            printf(" A ");
            // printf("\n Current AC Velocity: %f \n", st.exec_block->ac_speed);  
            st.counter_a -= st.exec_block->step_event_count; 
            st.step_count--;
        }       



        st.counter_c += st.exec_block->steps[C_AXIS];
        if (st.counter_c > st.exec_block->step_event_count)  
        {
            printf(" C ");
            // printf("\n Current AC Velocity: %f \n", st.exec_block->ac_speed);  
            st.counter_c -= st.exec_block->step_event_count; 
            st.step_count--;
        }      
/************************************************** a and c axis ****/


        printf("\n");  
        if (st.step_count == 0)  
        {          
            if ( ++motion_buffer_head == motion_buffer_size)  //starting a new block
            {   
                break;
                motion_buffer_head = 0;    
            } 
            st.exec_segment = NULL; 
        } 
    }



    return 0;
}

