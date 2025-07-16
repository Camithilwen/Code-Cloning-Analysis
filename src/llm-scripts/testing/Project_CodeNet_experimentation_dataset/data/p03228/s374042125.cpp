#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    ll d[2], k;
    cin >> d[0] >> d[1] >> k;

    int cnt = 0;
    rep(i, k) {
        int id = cnt % 2;
        if (d[id] % 2 == 1)
            --d[id];
        d[id] /= 2;
        d[1 - id] += d[id];
        ++cnt;
    }

    cout << d[0] << " " << d[1] << endl;

    return 0;
}