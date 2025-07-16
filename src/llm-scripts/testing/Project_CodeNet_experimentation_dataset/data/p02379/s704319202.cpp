#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int main(void) {

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    printf("%f\n", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));

    return 0;
}