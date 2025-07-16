#include<cstdio>

long double sqrt(double);

int main(void){
long double d;
double x1,y1,x2,y2,D;
scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
D=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
sqrt(D);
d=sqrt(D);
printf("% 8.8Lf\n",d);
return 0;
}

long double sqrt(double a){
int i;
long double b=3;
for(i=0;i<256;i++){
b=(b/2)+(a/(2*b));

}
return b;
}