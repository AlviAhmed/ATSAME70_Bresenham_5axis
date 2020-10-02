#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

// initial coordinate (xo,yo)
// destination coordinate (x1,y1)
void plotLine (int x0, int y0, int x1, int y1);

int main (void) {
    plotLine(0,0,1,5); 
    printf(" next: \n");
    plotLine(1,5,3,5); 
    printf(" next: \n");
    plotLine(3,5,-9,10); 
    printf(" next: \n");
    plotLine(-9,10,10,5); 
    printf(" next: \n");
    plotLine(10,5,8,-10); 
    printf(" next: \n");
}

void plotLine (int x0, int y0, int x1, int y1){  
    printf("\n Initial: (%d, %d) -> Final (%d, %d) \n\n",x0,y0,x1,y1);
    int x,y,dx, dy, sx, sy, err, e2;
    dx =  abs(x1-x0);
    sx = x0<x1 ? 1 : -1; //these values are later uses to increment the x and y values
    dy = -abs(y1-y0);
    sy = y0<y1 ? 1 : -1;
    err = dx+dy;  /* error value e_xy */  
    x = x0; 
    y = y0;
    while (1){ 
        printf("      ("); 
        printf("%d",x);
        printf(",");
        printf("%d",y);
        printf(") ");  
        printf("\n"); 
        if (x==x1 && y==y1) //if the beginning and end destination are the same coordinate
        { 
            break;
        } 
        e2 = 2*err;
        printf("Step      Co-ordinates \n");
        // printf("Step   Error  Co-ordinates\n");
        // if the error value is greater than deltay, that means line is getting steeper therefore increment the yaxis
        if (e2 >= dy)
        { 
            err += dy; /* e_xy+e_x > 0 */
            x += sx; 
            printf("x");
        } 
        if (e2 <= dx) 
        { 
            err += dx;
            y += sy; 
            printf("y");
        }  
        // printf("   error:%d", e2);
    }
} 


