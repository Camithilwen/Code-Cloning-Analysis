#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int m; cin >> m;
    vector<ll> d(m), c(m);
    for(int i = 0; i < m; i++)cin >> d[i] >> c[i];
    ll res = 0, ans = -1;
    for(int i = 0; i < m; i++) {
        res += c[i] * d[i];
        ans += c[i];
    }
    while(res > 9) {
        ans += res / 10;
        res = res / 10 + (res % 10);
    }
    cout << ans << endl;
}