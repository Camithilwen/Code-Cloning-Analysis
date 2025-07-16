#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    for(i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(i = 0; i < m; i++) {
        cin >> y[i];
    }
    ll retx = 0;
    for(k=0;k<n;k++){
        retx = (retx + k*x[k] - (n-1-k)*x[k])%MOD;
    }
    ll rety=0;
    for(k = 0; k < m; k++) {
        rety = (rety + k * y[k] - (m - 1 - k) * y[k]) % MOD;
    }

    cout << (rety*retx)%MOD << endl;
    return 0;
}