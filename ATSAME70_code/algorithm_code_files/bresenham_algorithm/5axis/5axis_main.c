#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 





void plotLine5D(int x1, int y1, int z1, int a1, int c1, int x2, int y2, int z2, int a2, int c2); 

int main (void) {    
  
  plotLine5D(0,0,0,0,0,1,2,3,4,5); 
  printf("next block \n \n");
  plotLine5D(1,2,3,4,5,9,10,-3,6,9); 
  printf("next block \n \n");
  plotLine5D(9,10,-3,6,9,-10,6,-3,-4,0); 
  printf("next block \n \n");
  plotLine5D(-10,6,-3,-4,0,0,1,3,3,4); 
  printf("next block \n \n");
  plotLine5D(0,1,3,3,4,5,8,6,2,1); 
  printf("next block \n \n");
  plotLine5D(5,8,6,2,1,2,2,5,4,9); 
  printf("next block \n \n"); 
  plotLine5D(0,0,0,0,0,2,2,2,2,2); 
  printf("next block \n \n"); 
  plotLine5D(1,1,1,1,1,9,8,7,-10,-10); 
  printf("next block \n \n");

}

void plotLine5D(int x1, int y1, int z1, int a1, int c1, int x2, int y2, int z2, int a2, int c2){   

  int dx, dy, dz, da, dc, xs, ys, zs, as, cs, p1, p2, p3, err; 
  dx =  abs(x2-x1);
  dy =  abs(y2-y1);
  dz =  abs(z2-z1);   
  da =  abs(a2-a1);  
  dc =  abs(c2-c1);   
  

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

  if  (a2 > a1){  
    as = 1;
  }else{ 
    as = -1;
  }       

  if  (c2 > c1){  
    cs = 1;
  }else{ 
    cs = -1;
  }      

  printf (" Destination: \n");
  printf("   ("); 
  printf("%d",x2);
  printf(",");
  printf("%d",y2);
  printf(",");
  printf("%d",z2);
  printf(",");
  printf("%d",a2);
  printf(",");
  printf("%d",c2);
  printf(") ");  
  printf("\n");   
  printf (" Origin: \n");
  printf("   ("); 
  printf("%d",x1);
  printf(",");
  printf("%d",y1);
  printf(",");
  printf("%d",z1);
  printf(",");
  printf("%d",a1);
  printf(",");
  printf("%d",c1);
  printf(") ");  
  printf("\n");   

  // Driving the xaxis 
  if (dx >= dy && dx >= dz) 
  { 
    /* x2 - x1 is greater than both y2 - y1 and z2 - z1, then is the axis that is doing most of the motion?*/ 
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
      printf(",");
      printf("%d",a1);
      printf(",");
      printf("%d",c1);
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
      printf(",");
      printf("%d",a1);
      printf(",");
      printf("%d",c1);
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
      printf(",");
      printf("%d",a1);
      printf(",");
      printf("%d",c1);
      printf(") ");  
      printf("\n");  
    }  
  }  

  // Driving the a axis
  if (da >= dc)
  {   
    p3 = 2 * dc - da; 
    while (a1 != a2) 
    {   
     printf("Step      Co-ordinates\n");
     a1 += as;  
     printf("a");
     if (p3 >= 0) 
     { 
       c1 += cs; 
       p3 -= 2 * da; 
        printf("c");
     }
     p3 += 2 * dc;
      printf("           ("); 
      printf("%d",x1);
      printf(",");
      printf("%d",y1);
      printf(",");
      printf("%d",z1);
      printf(",");
      printf("%d",a1);
      printf(",");
      printf("%d",c1);
      printf(") ");  
      printf("\n");  
    }  
  } 
  // Driving the c axis
  else if (dc >= da)
  {   
    p3 = 2 * da - dc; 
    while (c1 != c2) 
    {   
     printf("Step      Co-ordinates\n");
     c1 += cs;  
     printf("c");
     if (p3 >= 0) 
     { 
       a1 += as; 
       p3 -= 2 * dc; 
        printf("a");
     }
     p3 += 2 * da;
      printf("           ("); 
      printf("%d",x1);
      printf(",");
      printf("%d",y1);
      printf(",");
      printf("%d",z1);
      printf(",");
      printf("%d",a1);
      printf(",");
      printf("%d",c1);
      printf(") ");  
      printf("\n");  
    }  
  }

} 










