#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include </home2/reports-naoki709mm/C-lesson/section5/mylib.h>

#define NUM 4
#define DAT 1000
#define FILES
#define T 0.1
#define loop(i,n) for(i=0 ;i<n ;i++)
#define sqr(x) ((x)*(x))

#ifdef FILES //マクロ変数がFILESだった場合出力先をfwにす
#define OUTPUT fw
#else
#define OUTPUT stdout
#endif

void usage_print(){ //usageを表示後、終了
  printf("Usage : getdist [option] <file1> <file2>\n");
  printf("option :\n");
  printf("-h) Show this message\n");
  printf("-a) Show average,standard deviation,Min and Max\n");
  printf("-g) Show histogram\n");
}

void error_print(){ //エラー出力
  
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

void statistics(double dat[] ,int n ,FILE *fw){ 
  
  int i;
  double sum=0.0,std,ave;
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

  fprintf(OUTPUT ,"Ave : %lf\n",ave);
  fprintf(OUTPUT ,"Std : %lf\n",std);
  fprintf(OUTPUT ,"Min : %lf\n",min);
  fprintf(OUTPUT ,"Max : %lf\n",max);
}

void histogram(double dat[] ,int n ,FILE *fw){
  
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
    fprintf(OUTPUT ,"%4.2f - %4.2f : ",tmp,tmp+T);
    loop(j ,hst[i])
      fprintf(OUTPUT ,"*");
    fprintf(OUTPUT ,"\n");
  }
  
  free(hst);
  
}
    
int main(int argc ,char *argv[]){
  
  int n=0;
  char *tmp;
  char *fname_r;
  char *fname_w;
  char opt;
  double dat[DAT];
  double a;
  FILE *fr;
  FILE *fw;
  
  if(argc != NUM){ //引数が2つなければ終了
    usage_print();
    exit(1);
  }
  
  tmp=argv[1]; //オプション判定
  opt=judg_option(tmp); //optにaかgがはいる
  
  fname_r=argv[2]; //ファイルオープン
  fr=fRopen(fname_r);
  
  fname_w=argv[3];
  fw=fWopen(fname_w);
  
  while(fscanf(fr ,"%lf\n" ,&a) != EOF){
    dat[n]=a;
    n++;
  }
  
  switch((int)opt){
    case (int)'a':
      statistics(dat ,n ,fw);
      break;
    case (int)'g':
      histogram(dat ,n ,fw);
      break;
  }
  
  return 0;
}
