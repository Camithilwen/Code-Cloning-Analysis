#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i,N) cin >> x[i] >> y[i];
    double d=0;
    rep(i,N) rep(j,N)
        d += hypot(x[i]-x[j], y[i]-y[j]);
    printf("%.8f\n", d/N);
}
