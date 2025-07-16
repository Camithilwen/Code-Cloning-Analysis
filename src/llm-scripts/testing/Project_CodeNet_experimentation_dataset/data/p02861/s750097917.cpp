#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double sum = 0;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    cout << fixed;
    cout << setprecision(7) << sum / n << endl;
    return 0;
}