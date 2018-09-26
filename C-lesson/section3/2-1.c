#include <stdio.h>

int main(void){
  
  double x=0.0;
  int i;

  for(i=0 ;i<10 ;i++){
    x+=0.1;
    printf("%0.16f\n",x);
  }
  
  return 0;
}
