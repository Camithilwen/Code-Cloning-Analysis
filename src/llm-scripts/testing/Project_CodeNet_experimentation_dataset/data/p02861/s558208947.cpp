#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    double sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int xx = x[i] - x[j];
                int yy = y[i] - y[j];
                double d = sqrt(xx*xx + yy*yy);
                sum += d;
            }
        }
    }
    double ans = sum / (double)n;
    printf ("%.7lf", ans);
}