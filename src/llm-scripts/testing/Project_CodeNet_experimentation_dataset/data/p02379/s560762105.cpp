#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    double a, b, c, d, x, y, ans;
    cin >> a >> b >> c >> d;
    x = a - c;
    y = b - d;
    ans = sqrt(x*x + y*y);
    printf("%f", ans);
    return 0;
}