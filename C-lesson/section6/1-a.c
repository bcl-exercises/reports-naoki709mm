#include <stdio.h>
#include <math.h>

#define A 1.0
#define DT 0.01
#define loop(i ,n) for(i=0 ;i<n ;i++)

int main(void){
  
  int i;
  double t=DT;
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
    loop(i ,1000){
      fprintf(gp ,"%lf\t%lf\n" ,t ,A*exp(t));
      t+=DT;
    }
    fprintf(gp ,"e\n");

    pclose(gp);
  }
  
  return 0;
}
