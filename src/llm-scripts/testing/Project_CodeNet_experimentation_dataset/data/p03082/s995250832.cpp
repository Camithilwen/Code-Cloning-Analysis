#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(16);
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;
    vector<ll> dp(x+1);
    vector<ll> s(n);
    for(auto &e: s) cin >> e;
    sort(s.begin(), s.end(), greater<>());

    dp[x] = 1;
    for(ll k=1; k<=n; k++) {
        vector<ll> pre(x+1);
        swap(dp, pre);

        for(ll i=0; i<=x; i++) {
            (dp[i%s[k-1]] += pre[i]) %= MOD;
            (dp[i] += pre[i]*(n-k)) %= MOD;
        }
    }

    {
        ll s = 0;
        for(ll i=0; i<=x; i++)
            (s += dp[i]*i) %= MOD;
        cout << s << endl;
    }
}
