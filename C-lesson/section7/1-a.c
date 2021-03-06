#include <stdio.h>
#include <math.h>

#define A 1.0
#define DT 0.1

int main(void){
  
  double t=DT;
  double x;
  double tmp;
  double dd;
  FILE *gp;

  if((gp=popen("gnuplot -persist" ,"w")) == NULL){
    printf("error\n");
    return 1;
  }
  else{
    fprintf(gp ,"unset key\n");
    fprintf(gp ,"set xlabel 't'\n");
    fprintf(gp ,"set ylabel 'exp(t)'\n");
    fprintf(gp ,"plot '-' with lines linetype 1\n");
    do{
      x=A*exp(t);
      fprintf(gp ,"%lf\t%lf\n" ,t ,x);
      tmp=x;
      t+=DT;
      dd=tmp-x;
    }while(t <= 10);
    fprintf(gp ,"e\n");
    
    pclose(gp);
  }
  
  return 0;
}
