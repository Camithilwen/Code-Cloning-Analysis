#include<stdio.h>
#include<math.h>
int main(){
    double x1, x2;
    double y1, y2;
    double L, l;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    L = pow(x2-x1, 2.0) + pow(y2-y1, 2.0);
    l = sqrt(L);
    printf("%f", l);
    return 0;
}