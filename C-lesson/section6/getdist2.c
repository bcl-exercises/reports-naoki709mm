#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mylib.h"

#define NUM 2
#define DAT 1000
#define T 0.1
#define loop(i,n) for(i=0 ;i<n ;i++)
#define sqr(x) ((x)*(x))

void usage_print(){ //usageを表示後、終了
  
  printf("Usage : getdist2 [option] <file> or <program> | getdist2 [option]\n");
  printf("option :\n");
  printf("-h) Show this message\n");
  printf("-a) Show average,standard deviation,Min and Max\n");
  printf("-g) Show histogram\n");
}

void error_print(){
  
  fprintf(stderr, "メモリが確保できません\n");
  exit(1);
}

char judg_option(char *opt){ //オプション判定 -aだとa,-gだとgを返す
  
  switch((int)opt[1]){ //-を除いてint型に変換
    case (int)'h':
      usage_print();
      exit(0);
    case (int)'a':
    case (int)'g':
      return opt[1];
    default:
      usage_print();
      exit(1);
      
  }
}

void statistics(double dat[] ,int n){
  
  int i;
  double sum=0.0;
  double std;
  double ave;
  double min=dat[0],max=dat[0];
  
  loop(i ,n){ //平均値と最大値と最小値
    sum+=dat[i];
    if(dat[i] < min)
      min=dat[i];
    if(dat[i] > max)
      max=dat[i];
  }
  ave=sum/n;
  
  sum=0.0; //標準偏差
  loop(i ,n)
    sum+=sqr(dat[i]-ave);
  std=sqrt(sum/n);

  printf("AVE : %lf\n",ave);
  printf("STD : %lf\n",std);
  printf("MIN : %lf\n",min);
  printf("MAX : %lf\n",max);
}

void histogram(double dat[] ,int n){
  
  int i,j;
  int pnt;
  int t;
  double tmp;
  int *hst;
  
  t=1/T; //Tの逆数
  
  if((hst=(int*)calloc(t,sizeof(int))) == NULL) //メモリの確保ができなかった場合、エラー出力
    error_print();
  
  loop(i ,n){ //ポイント数
    pnt=dat[i]/T;
    hst[pnt]++;
  }

  loop(i ,t){
    tmp=i*T;
    printf("%4.2f - %4.2f : ",tmp,tmp+T);
    loop(j ,hst[i])
      printf("*");
    printf("\n");
  }
  
  free(hst);
  
}
    
int main(int argc ,char *argv[]){
  
  int n=0;
  char *tmp;
  char *fname;
  char opt;
  double dat[DAT];
  double a;
  FILE *fr;
  
  if(argc != NUM && argc != NUM+1){ //引数が2つか3つなければ終了
    usage_print();
    exit(1);
  }
  
  fname=argv[argc-1]; //ファイルがあればfnameはファイル名,なければオプション
  fr=fRPopen(fname);
  
  tmp=argv[1]; //オプション判定
  opt=judg_option(tmp); //optにaかgがはいる
  
  while(fscanf(fr ,"%lf\n" ,&a) != EOF){
    dat[n]=a;
    n++;
  }
  
  switch((int)opt){
    case (int)'a':
      statistics(dat ,n);
      break;
    case (int)'g':
      histogram(dat ,n);
      break;
  }

  return 0;
}
  
