#include <stdio.h>

#define loop(i,n) for(i=0 ;i<n ;i++)

int main(void){
  int i;
  int n;
  float x=0.1;
  
  n=10000000;

  loop(i,n){
    x/=0.1;
    x*=10.0;
  }

  return 0;
}
