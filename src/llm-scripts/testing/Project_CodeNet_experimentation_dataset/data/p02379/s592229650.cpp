#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    printf("%lf", sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}
