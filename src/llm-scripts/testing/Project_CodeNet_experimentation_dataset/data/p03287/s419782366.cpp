#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> s(n+1);
    rep(i,n) {
        ll a;
        cin >> a;
        s[i+1] = (s[i] + a)%m;
    }
    ll ans = 0;
    map<int,ll> mp;
    for (int i = 0; i <= n; i++) {
        ans += mp[s[i]];
        mp[s[i]]++;
    }
    cout << ans << endl;
    return 0;
}