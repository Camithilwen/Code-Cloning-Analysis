#include <bits/stdc++.h>
using namespace std;

// double mathdist(double, double, double, double);

int main()
{
    /* 始めからdouble型で読み込むべし */
    /* 読み込み時のキャストは危険 */
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // cout << mathdist(x1, x2, y1, y2) << endl;
    cout << fixed << setprecision(cout.precision()) << sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2)) << endl;
    return 0;
}

// double mathdist(double x1, double x2, double y1, double y2)
// {
//     double dxsq, dysq, res;

//     constexpr double EPS = numeric_limits<double>::epsilon();
//     if (abs(x1 - x2) <= EPS)
//     {
//         dxsq = 0.0;
//     }
//     else
//     {
//         dxsq = pow(abs(x1 - x2), 2);
//     }
//     if (abs(y1 - y2) <= EPS)
//     {
//         dysq = 0.0;
//     }
//     else
//     {
//         dysq = pow(abs(y1 - y2), 2);
//     }

//     return res = sqrt(dxsq + dysq);
// }
