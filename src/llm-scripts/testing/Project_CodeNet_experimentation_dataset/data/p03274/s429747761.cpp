#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, k; cin >> n >> k;
    V<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = 1e9;
    for(int l = 0; l <= n - k; l++){
        ll r = l + k - 1;
        ans = min(ans, abs(v[l]) + abs(v[l] - v[r]));
        ans = min(ans, abs(v[r]) + abs(v[r] - v[l]));
    }
    cout << ans << endl;


    return 0;
}
