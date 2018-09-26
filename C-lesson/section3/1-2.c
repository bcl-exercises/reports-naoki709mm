#include <stdio.h>

//#define MAX 3 
//配列はコンパイル時に大きさを決めるため、実行時に値を代入するconstだと正常に値がでない。よって#defineに書き換える

const int  MAX=3;

int main(void){
  
  int a[MAX];
  int i=0;
  
  for(i=0 ;i<MAX ;i++){
    a[i]=0;
    printf("%d\n",a[i]);
  }
  
  return 0;
}
