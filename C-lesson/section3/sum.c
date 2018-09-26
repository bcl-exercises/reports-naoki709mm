#include <stdio.h>
#include <stdlib.h>

#define NUM 3 

int main(int argc ,char *argv[]){

  int i;
  double sum=0.0;
  
  if(argc != NUM){ //引数の数がNUM個でなかった場合以下を表示してプログラムを終了する
    printf("Usage : sum <num1> <num2>\n");
  }
  
  else{
    for(i=0 ;i<NUM ;i++){
      sum+=atof(argv[i]);
    }
    printf("Ans : %lf\n",sum);
  }

  return 0;
}
