#include<stdio.h>
#include<string.h>
#define SIZE 1002
int main(){

  int i,j;
  int na,nb,nc,n;
  int a[SIZE],b[SIZE],c[SIZE],d[SIZE];
  int data[SIZE];

  while(1){
  scanf("%d %d %d",&na,&nb,&nc);
  if(na==0 && nb==0 && nc==0)break;
  scanf("%d",&n);

  for(i=1;i<=na+nb+nc;i++)data[i]=2;
  for(i=0;i<n;i++){
    scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    if(d[i]==1){
      data[a[i]]=data[b[i]]=data[c[i]]=1;
    }
  }

  for(i=0;i<n;i++){
    if(d[i]==0){
      if(data[a[i]]==1 && data[b[i]]==1)data[c[i]]=0;
      else if(data[a[i]]==1 && data[c[i]]==1)data[b[i]]=0;
      else if(data[b[i]]==1 && data[c[i]]==1)data[a[i]]=0;
    }
  }
  
  for(i=1;i<=na+nb+nc;i++){
    printf("%d\n",data[i]);
  }
  }

  return 0;
}