#include<stdio.h>
main(){
  int i,d,s;
  while(scanf("%d",&d)!=EOF){
    s=0;
    for(i=0;i<600/d;i++){
      s+=(d*((d*i)*(d*i)));
    }
    printf("%d\n",s);
  }
  return 0;
}