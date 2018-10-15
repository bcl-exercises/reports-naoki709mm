#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 9.8
#define pi 3.141592
#define H 0.01

void usege_print(){
  
  printf("Usage : 2 <mass> <angle> <speed>\n");
  printf("----------------------------------\n");
  printf("        0 kg < mass\n");
  printf("        0° < angle < 90°\n");
  printf("        0 m/s < speed\n");
  printf("----------------------------------\n");
  exit(1);
}


int main(int argc ,char *argv[]){
  
  double x=0.0 ,y=0.0;
  double v ,vx ,vy;
  double m;
  double t=H;
  double h=H;
  double theta;
  FILE *gp;
  
  if(argc != 4)
    usege_print();
  
  if((gp=popen("gnuplot -persist" ,"w")) == NULL){
    printf("error\n");
    return 1;
  }
  else{
    v=atof(argv[argc-1]);
    m=atof(argv[argc-3]);
    theta=atof(argv[argc-2]);

    if(v <= 0 || m <= 0 || theta <= 0 || theta >= 90) //エラー判定
      usege_print();
    
    theta/=180*pi; //ラジアンにする
    
    fprintf(gp ,"unset key\n");  //gnuplot
    fprintf(gp ,"set xlabel 'x'\n");
    fprintf(gp ,"set ylabel 'y'\n");
    fprintf(gp ,"plot '-' with lines linetype 1\n");
    
    vx=v*cos(theta); //速度をx ,y方向に分ける
    vy=v*sin(theta);

    do{ //オイラー法
      fprintf(gp ,"%lf\t%lf\n" ,x ,y);
      x=vx*t;
      y+=h*(-G*t+vy);
      t+=H;
    }while(y >= 0);
    fprintf(gp ,"e\n"); //gnuplot終了
    
    pclose(gp);
  }
  
  return 0;
}
