#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i], a[i]--;

    ll ret = a[0]!=0;
    vector<vector<ll>> g(n);
    FOR(i, 1, n) {
        g[i].push_back(a[i]);
        g[a[i]].push_back(i);
    }

    function<ll(ll,ll,ll)> dfs = [&](ll v, ll p, ll d) {
        ll ma = 1;
        for(auto to: g[v]) if(p != to) {
            ll val = dfs(to, v, d+1);
            dump(v, to, val);
            chmax(ma, val+1);
        }
        bool flag = false;
        if(ma == k && d+ma-1 > k) {
            ma = 0;
            ret++;
            flag = true;
        }
        dump(v, d, ma, flag);
        return ma;
    };
    dfs(0, -1, 0);

    cout << ret << endl;

    return 0;
}