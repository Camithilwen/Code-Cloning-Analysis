#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<double> X(N), Y(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> X[i] >> Y[i];
    }
    vector<int> c(N);
    int M = 3e5;
    double pi = acos(0) * 2;
    for ( int k = 0; k < M; k++ ) {
        double t = 2 * pi * k / M;
        int mi;
        double mx = -2e6;
        for ( int i = 0; i < N; i++ ) {
            double x = X[i]*cos(t) - Y[i]*sin(t);
            if ( mx < x ) {
                mx = x;
                mi = i;
            }
        }
        c[mi]++;
    }
    for ( int i = 0; i < N; i++ ) {
        cout << c[i] / (double)M << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}