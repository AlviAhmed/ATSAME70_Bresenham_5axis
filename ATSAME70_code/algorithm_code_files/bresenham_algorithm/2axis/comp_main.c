#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>  

int main (void){ 
  int sx, x0, x1;  
  printf(" Initial Condition: sx = x0<x1 ? 1:-1 \n \n");
  x0 = 1; 
  x1 = 1; 
  sx = x0<x1 ? 1 : -1;
  printf(" sx with x0=1 and x1 = 1: \n %d",sx);
  x0 = 0; 
  x1 = 1; 
  sx = x0<x1 ? 1 : -1;
  printf(" \n sx with x0 = 0 and x1 = 1: \n %d",sx);
  x0 = 1; 
  x1 = 0; 
  sx = x0<x1 ? 1 : -1;
  printf(" \n sx with x0 = 1 and x1 = 0: \n %d",sx);
  x0 = 0; 
  x1 = 0; 
  sx = x0<x1 ? 1 : -1;
  printf(" \n sx with x0 = 0 and x1 = 0: \n %d",sx);
  return 0;
}
