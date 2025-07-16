#include<stdio.h>
#include<cmath>

int main(){
double x1,x2,y1,y2,r,R;
scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
r=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
R=sqrt(r);
printf("%lf\n",R);
return 0;
}