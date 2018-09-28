#include <stdio.h>
#include <stdlib.h>

#define loop(i ,n) for(i=0 ;i<n ;i++)

void error_print(){
  
  fprintf(stderr, "メモリが確保できません\n");
  
  exit(1);
}
  
int main(int argc ,char *argv[]){
  
  int n;
  int i,j;
  int **a;
  
  if(argc != 2){ 
    printf("Usage : array <num>\n");
    return 1;
  }
  
  n=atoi(argv[1]);
  
  a=(int**)calloc(n,sizeof(int*)); //2次元配列分のメモリの確保
  loop(i ,n)
    a[i]=(int*)calloc(n,sizeof(int*));
  
  if(a == NULL) //メモリの確保ができなかった場合、エラー出力
    error_print();
  loop(i ,n){
    if(a[i] == NULL)
      error_print();
  }
  
  loop(i ,n) //単位行列の作成
    a[i][i]=1;
  
  loop(i ,n){
    loop(j ,n)
      printf("%d  ",a[i][j]);
    printf("\n");
  }
  
  loop(i ,n)
    free(a[i]);
  free(a);
  
  return 0;
}
