#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include </home2/reports-naoki709mm/C-lesson/section5/mylib.h>

#define NUM 3
#define DAT 1000
#define T 0.1
#define loop(i,n) for(i=0 ;i<n ;i++)
#define sqr(x) ((x)*(x))

void usage_print(){ //usageを表示後、終了
  
  printf("Usage : getdist [option] <file>\n");
  printf("option :\n");
  printf("-h) Show this message\n");
  printf("-a) Show average,standard deviation,Min and Max\n");
  printf("-g) Show histogram\n");
}

void error_print(){
  
  fprintf(stderr, "メモリが確保できません\n");
  exit(1);
}

char Options(char *opt){ //オプション判定 -aだとa,-gだとgを返す
  
  if(strcmp(opt,"-h") == 0){
    usage_print();
    exit(0);
  }
  
  if(strcmp(opt,"-a") == 0 )
    return 'a';
  else if(strcmp(opt,"-g") == 0)
    return 'g';
  else{
    usage_print();
    exit(1);
  }
}

void opt_a(double dat[] ,int n){
  
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

void opt_g(double dat[] ,int n){
  
  int i,j;
  int tmp;
  int t;
  double min=0.0,max=T;
  int *hst;
  char **pnt;

  t=1/T; //Tの逆数
  
  if((hst=(int*)calloc(t,sizeof(int))) == NULL) //メモリの確保ができなかった場合、エラー出力
    error_print();
  
  if((pnt=(char**)calloc(t,sizeof(char*))) == NULL) //メモリの確保ができなかった場合、エラー出力
    error_print();
  loop(i ,t)
    if((pnt[i]=(char*)calloc(DAT,sizeof(char*))) == NULL)
      error_print();
  
  loop(i ,n){ //ポイント数
    tmp=dat[i]/T;
    hst[tmp]++;
  }
  
  loop(i ,t){ //配列pntに個数分*を入れる
    loop(j ,hst[i])
      pnt[i][j]='*';
  }

  loop(i ,t){
    printf("%4.2f - %4.2f : %s\n",min,max,pnt[i]);
    min=max;
    max+=T;
  }
  
  free(hst);
  free(pnt);
  loop(i ,t)
    free(pnt[i]);
  
}
    
int main(int argc ,char *argv[]){
  
  int n=0;
  char *tmp;
  char *fname;
  char opt;
  double dat[DAT];
  double a;
  FILE *fr;
  
  if(argc != NUM){ //引数が2つなければ終了
    usage_print();
    exit(1);
  }
  
  tmp=argv[1]; //オプション判定
  opt=Options(tmp); //optにaかgがはいる
  
  fname=argv[2]; //ファイルオープン
  fr=fRopen(fname);
  
  while(fscanf(fr ,"%lf\n" ,&a) != EOF){
    dat[n]=a;
    n++;
  }
  
  if(opt == 'a')
    opt_a(dat ,n);
  
  if(opt == 'g')
    opt_g(dat ,n);

  return 0;
}
  
