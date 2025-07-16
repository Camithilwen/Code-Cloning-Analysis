#include<stdio.h>
int main(){
  int i,j,x,N,M,a[1000],b,c[1000];
  scanf("%d%d",&N,&M);
  //syokika
  for(i=0;i<1000;i++){
    c[i]=0;
  }
  //
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<M;i++){
    scanf("%d",&b);
    for(j=0;j<N;j++){
      if(a[j]<=b){
	c[j]++;
	break;
      }
    }
  }
  x=0;
  for(i=0;i<M;i++){
    if(c[x]<c[i])x=i;
  }
  printf("%d\n",x+1);
  return 0;
}