#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    double P1x,P1y,P2x,P2y;
    cin >> P1x >> P1y >> P2x >> P2y;
    printf("%.8lf\n", sqrt((P1x-P2x)*(P1x-P2x)+(P1y-P2y)*(P1y-P2y)));
    return 0;
}