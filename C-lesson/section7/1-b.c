#include <stdio.h>
#include <math.h>

#define H 0.001

int main(void){
  
  int t;
  int h=1/H;
  double x=1.0;
  
  for(t=0 ;t<h ;t++){ //オイラー法を刻み値の逆数回繰り返す
    x+=H*x;
    printf("e = %lf\n" ,x);
  }
  
  printf("\n");
  printf("  真値     : e = %lf\n" ,exp(1));
  
  
  return 0;
}
