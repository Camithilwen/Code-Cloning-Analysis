#include <iostream>
#include <cmath>
using namespace std;

int main(void){

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed << sqrt(pow(fabs(x1-x2),2)+pow(fabs(y1-y2),2)) << endl;
    return 0;
}

