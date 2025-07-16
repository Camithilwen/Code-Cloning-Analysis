#include <stdio.h>
#include <math.h>
int main(){
  double vx,vy,v,x1,x2,y1,y2;
  scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2);
  vx=(x2-x1)*(x2-x1);
  vy=(y2-y1)*(y2-y1);
  v=vx+vy;
  printf("%0.8f\n",sqrt(v));
  return 0;
}