#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    const double PI=3.1415926535897932;
    int r; cin >> r;
    double l = (double) (2 * r) * PI;
    cout << fixed << setprecision(15) << l << endl;
}
