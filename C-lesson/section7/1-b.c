#include <stdio.h>
#include <math.h>

#define H 0.001

int main(void){
  
  int t;
  double x=1.0;
  
  for(t=0 ;t<1/H ;t++){ //オイラー法を刻み値の逆数回繰り返す
    x+=H*x;
  }
  
  printf("オイラー法 : e = %lf\n" ,x);
  printf("  真値     : e = %lf\n" ,exp(1));
  
  
  return 0;
}
