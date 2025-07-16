#include<stdio.h>
const int MAX_V=10000;
int prime[MAX_V+1];
int main(){
  int i,k,n,p,q,v;
  for(i=2;i<=MAX_V;i++){
    prime[i]=1;
  }
  for(i=2;i*i<=MAX_V;i++){
    if(prime[i]){
      for(k=2*i;k<=MAX_V;k+=i){
        prime[k]=0;
      }
    }
  }
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    for(v=2;v<=n-2;v++){
      int isprime=prime[v]*prime[v+2];
      if(isprime)p=v,q=v+2;
    }
    printf("%d %d\n",p,q);
  }
  return 0;
}