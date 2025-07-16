#include<stdio.h>
#include<math.h>
int main(){
    double x1, x2;
    double y1, y2;
    double L, l;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    L = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    l = sqrt(L);
    printf("%f", l);
    return 0;
}