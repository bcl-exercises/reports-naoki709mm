#include <stdio.h>
#include <stdlib.h>

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
  for(i=0 ;i<n ;i++)
    a[i]=(int*)calloc(n,sizeof(int*));
  
  if(a == NULL){ //メモリの確保ができなかった場合、エラー出力
    fprintf(stderr, "メモリが確保できません\n");
    return 1;
  }
  for(i=0 ;i<n ;i++)
    if(a[i] == NULL){
      fprintf(stderr, "メモリが確保できません\n");
      return 1;
    }
  
  for(i=0 ;i<n ;i++) //単位行列の作成
    a[i][i]=1;
  
  for(i=0 ;i<n ;i++){
    for(j=0 ;j<n ;j++)
      printf("%d  ",a[i][j]);
    printf("\n");
  }
  
  for(i=0 ;i<n ;i++)
    free(a[i]);
  free(a);
  
  return 0;
}
