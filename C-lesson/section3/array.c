#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char *argv[]){
  
  int n;
  int i;
  int *a;
  
  if(argc != 2){ 
    printf("Usage : array <num>\n");
    return 1;
  }
  
  n=atoi(argv[1]);
  
  a=(int*)calloc(n,sizeof(int)); //メモリの確保
  
  if(a == NULL){ //メモリの確保ができなかった場合、エラー出力
    fprintf(stderr, "メモリが確保できません\n");
    return 1;
  }
  
  for(i=0 ;i<n ;i++){
    a[i]=i;
    printf("%d\n",a[i]);
  }
  
  free(a);
  
  return 0;
}
