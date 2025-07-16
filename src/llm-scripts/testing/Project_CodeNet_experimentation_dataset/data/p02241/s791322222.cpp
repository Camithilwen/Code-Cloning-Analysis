#include<stdio.h>
#include<limits.h>
#define NIL -1
static const int MAX = 500;
static const int INFTY = (1<<21);
int n, i, j, e, v, sum, u , minV;
main(){
 
  int M[MAX][MAX], key[MAX], L[MAX],A[MAX];
  
  scanf("%d", &n);
  
  for ( i = 0; i< n; i++ ){
    for ( j = 0; j < n; j++ ){
      scanf("%d", &e);
      M[i][j] = (e==-1)?INFTY:e;
    }
  }

  for(i = 0; i < n; i++){
    key[i] = INT_MAX;
    L[i] = NIL;
    A[i] = NIL;
  }
  
  key[0]=0;
  
  for(;;){
    
    u = NIL;
    
    minV = INT_MAX;
    
    for(i = 0;  i < n; i++){
      
      if(key[i] < minV && A[i] == NIL){
        
        u = i;
        
        minV = key[i];
        
      }
      
    }  
    if(u == NIL)break;
    
    A[u] = u; 
    
    for(v = 0; v < n; v++){
      if(M[u][v] < key[v] && A[v] == NIL){
        key[v] = M[u][v];
        L[v] = u;
      }
    }
  }
  
  sum = 0;
  
  for ( i = 0; i < n; i++ ){
    if ( L[i] != -1 ) sum +=M[L[i]][i];
  }
  
  printf("%d\n", sum);
  
  
  return 0;
}