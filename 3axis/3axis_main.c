#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 



void plotline(int x1, int y1, int z1, int x2, int y2, int z2); 

int main (void) {   

  plotline(-1,1,1,5,3,-1); 
  printf(" next: \n");
  plotline(-5,3,-1,6,-8,3); 
  printf(" next: \n");
  plotline(6,9,1,6,1,-2); 
  printf(" next: \n"); 

}

void plotline(int x1, int y1, int z1, int x2, int y2, int z2){   

  int dx, dy, dz, xs, ys, zs, p1, p2; 
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

  printf (" Destination: \n");
  printf("   ("); 
  printf("%d",x2);
  printf(",");
  printf("%d",y2);
  printf(",");
  printf("%d",z2);
  printf(") ");  
  printf("\n");   
  printf (" Origin: \n");
  printf("   ("); 
  printf("%d",x1);
  printf(",");
  printf("%d",y1);
  printf(",");
  printf("%d",z1);
  printf(") ");  
  printf("\n");   

  // Driving the xaxis 
  if (dx >= dy && dx >= dz) 
  { 
    /* x2 - x1 is greater than both y2 - y1 and z2 - z1, then this is the axis that is doing most of the motion*/ 
    p1 = 2 * dy - dx; 
    p2 = 2 * dz - dx;    

    while (x1 != x2) 
    {    
      
      printf("Step      Co-ordinates\n");
      x1 += xs; 
      printf("x");
      if (p1 >= 0) 
      { 
        y1 += ys; 
        p1 -= 2 * dx;
        printf("y");
      }
      if (p2 >= 0) 
      { 
        z1 += zs;
        p2 -= 2 * dx; 
        printf("z");
      }
      p1 += 2 * dy; 
      p2 += 2 * dz;  
      
      printf("           ("); 
      printf("%d",x1);
      printf(",");
      printf("%d",y1);
      printf(",");
      printf("%d",z1);
      printf(") ");  
      printf("\n");   

    } 
  }  
  // Driving the y axis
  else if (dy >= dx && dy >= dz) 
  {    
    p1 = 2 * dx - dy; 
    p2 = 2 * dz - dy;   
    while (y1 != y2) 
    {  
      printf("Step      Co-ordinates\n");
      y1 += ys;  
      printf("y");
      if (p1 >= 0) 
      { 
        x1 += xs; 
        p1 -= 2 * dy;  
        printf("x");
      } 
      if (p2 >= 0) 
      { 
        z1 += zs; 
        p2 -= 2 * dy; 
        printf("z");
      } 
      p1 += 2 * dx; 
      p2 += 2 * dz;  

      printf("           ("); 
      printf("%d",x1);
      printf(",");
      printf("%d",y1);
      printf(",");
      printf("%d",z1);
      printf(") ");  
      printf("\n");  
    } 
  }  

  // Driving the z axis
  else 
  {   
    p1 = 2 * dy - dz; 
    p2 = 2 * dx - dz;  
    while (z1 != z2) 
    {   

     printf("Step      Co-ordinates\n");
     z1 += zs;  
     printf("z");
     if (p1 >= 0) 
     { 
       y1 += ys; 
       p1 -= 2 * dz; 
        printf("y");
     }
     if (p2 >= 0) 
     {  
       x1 += xs; 
       p2 -= 2 * dz; 
       printf("x");
     }
     p1 += 2 * dy;
     p2 += 2 * dx; 
     
      printf("           ("); 
      printf("%d",x1);
      printf(",");
      printf("%d",y1);
      printf(",");
      printf("%d",z1);
      printf(") ");  
      printf("\n");  
    } 
  }
}
