#include <stdio.h>

int main(void){

  double x=0.0;
  
  while(1){ //0.1を10回足しても1.0にはならず、ループ文を永遠に抜けることができない。
    x+=1.0;
    if(x==10.0)
      break;
  }

  return 0;
}
