#include <iostream>
#include <string>
using namespace std;
string A[] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday",
"Wednesday" };
int D[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
    int m, d, B[13];
    B[0] = 1;
    for (int i = 1; i <= 12; ++i) B[i] = B[i-1] + D[i];
    while (cin >> m >> d) {
        if (!(m | d)) break;
        int t = B[m-1] + d - 2;
        cout << A[t%7] << endl;
    }
    return 0;
}