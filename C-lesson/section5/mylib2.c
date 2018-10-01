#include <stdio.h>
#include <stdlib.h>

FILE *fRopen(char *fname){
  FILE *fp;
  if((fp=fopen(fname ,"r")) == NULL){
    fprintf(stderr, "Failed to open %s\n",fname);//エラー出力後プログラムを終了
    exit(1);
  }
  else
    return fp;
}

FILE *fWopen(char *fname){
  FILE *fp;
  if((fp=fopen(fname ,"w")) == NULL){
    fprintf(stderr, "Failed to open %s\n",fname);//エラー出力後プログラムを終了
    exit(1);
  }
  else
    return fp;
}

int main(int argc ,char **argv){
  double a;
  FILE *fp;
  
  fp = stdin;
  
  while((fscanf(fp,"%lf\n",&a)) != EOF){
    printf("%lf\n",a);
  }
  
  return 0;
}
