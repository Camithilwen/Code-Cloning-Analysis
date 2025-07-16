#include<stdio.h>
#define INF (1<<30)-1
int main(){
  int n;
  scanf("%d",&n);
  int s[n];
  int i,j,c=INF;
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
    if(s[i]<c) c = s[i];
  }
  for(i=1;i<=c;i++){
    int ok = 0;
    for(j=0;j<n;j++) if(s[j]%i!=0) ok = 1;
    if(ok == 0) printf("%d\n",i);
  }
}