#include<stdio.h>
#include<math.h>
int main(){

  double x1,x2,y1,y2,ans;

  scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);

  ans=(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

  printf("%lf\n",sqrt(ans));


  return 0;
}


 