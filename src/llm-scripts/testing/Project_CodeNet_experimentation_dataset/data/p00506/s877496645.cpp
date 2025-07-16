#include <stdio.h>
int main(){
  int a,i;
  long long b,c,d,j;
  scanf("%d",&a);
  if(a==2){
    scanf("%lld %lld",&b,&c);
    if(b>c)i=c;
    else i=b;
    for(j=1;j<=i;j++)if(b%j==0&&c%j==0)printf("%lld\n",j);
  }else {
    scanf("%lld %lld %lld",&b,&c,&d);
    if(b<c&&b<d)i=b;
    if(c<b&&c<d)i=c;
    if(d<c&&d<b)i=d;
    for(j=1;j<=i;j++)if(b%j==0&&c%j==0&&d%j==0)printf("%lld\n",j);
  }
  return 0;
}