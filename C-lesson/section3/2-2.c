#include<stdio.h>

int main(void){
  
  float x=0.0;
  int i;

  for(i=0 ;i<10 ;i++){
    x+=0.1;
    printf("%0.16f\n",x); //doubleよりも差がおおきくなる.
  }

  return 0;
}
