#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 998244353;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int n;
    cin >> n;
    vector<ll> d(n);
    rep(i, n) {
        cin >> d[i];
        if(i == 0 && d[i] != 0) {
            cout << 0 << endl;
            return 0;
        }
        else if(i != 0 && d[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    map<ll,ll> mp;
    rep(i, n) {
        ++mp[d[i]];
    }
    ll ans = 1;
    repl(i, 1, n) {
        ans *= mp[d[i]-1];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}