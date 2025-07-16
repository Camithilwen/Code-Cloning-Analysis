#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double x = (double)(x2 - x1) * (double)(x2 - x1);
    double y = (double)(y2 - y1) * (double)(y2 - y1);
    cout << fixed << setprecision(6) << (double)sqrt(x+y) << endl;
    return 0;
}
