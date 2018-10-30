#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 9.8
#define PI 3.141592
#define H 0.1

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
  double h=H;
  double theta;
  
  if(argc != 4)
    usege_print();
  
  v=atof(argv[argc-1]);
  m=atof(argv[argc-3]);
  theta=atof(argv[argc-2]);
  
  if(v <= 0 || m <= 0 || theta <= 0 || theta >= 90) //エラー判定
    usege_print();
  
  theta=theta/180*PI; //ラジアンにする

  v=v*1000/3600; //速度をkm/hrからm/sに変換
  
  vx=v*cos(theta); //速度をx ,y方向に分ける
  vy=v*sin(theta);
  
  do{
    vy=vy-h*G;
    y=y+h*vy;
    x=x+h*vx;
  }while(y >= 0);
  
  printf("%lf\n",x);

  
  return 0;
}
