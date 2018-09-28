#include <stdio.h>
#include <stdlib.h>

FILE *fRopen(char *fname){
  FILE *fp;
  if((fp=fopen(fname ,"r")) == NULL){
    fprintf(stderr, "Failed to open %s\n",fname);//エラー出力後プログラムを終了
    exit(1);
  }
  
  return fp;
}

FILE *fWopen(char *fname){
  FILE *fp;
  if((fp=fopen(fname ,"w")) == NULL){
    fprintf(stderr, "Failed to open %s\n",fname);//エラー出力後プログラムを終了
    exit(1);
  }
  
  return fp;
}

int main(int argc ,char *argv[]){
  
  int a;
  char *fname;
  FILE *fp;

  fname=argv[1];
  
  if(argc != 2){ 
    printf("Usage : mylib <Filename>\n");
    return 1;
  }
  
  fp=fRopen(fname);
  
  
  return 0;
}
