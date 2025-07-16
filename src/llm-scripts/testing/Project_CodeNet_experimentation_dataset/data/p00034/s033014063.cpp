#include <cstdio>

double l[10],v1,v2;

int main(){
  while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",l,l+1,l+2,l+3,l+4,l+5,l+6,l+7,l+8,l+9,&v1,&v2)){
    double p=0;
    for(int i=0; i<10; i++) p+=l[i];
    p=p*v1/(v1+v2);
    for(int i=0; i<10; i++){
      if(p>l[i]) p-=l[i];
      else{
	printf("%d\n",i+1);
	break;
      }
    }
  }
}