#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 2

int main(int argc ,char *argv[]){
  
  int n;
  int i;
  
  if(argc != NUM){ 
    printf("Usage : genrand <num>\n");
    return 1;
  }
  
  n=atoi(argv[1]);
  
  srand((unsigned)time(NULL)); //シード値を時間で初期化
  
  for(i=0 ;i<n ;i++){
    printf("%lf\n",(double)rand()/RAND_MAX); //乱数で生成できる値の最大値で割ることで0から1の値とする
  }
  
  return 0;
}
