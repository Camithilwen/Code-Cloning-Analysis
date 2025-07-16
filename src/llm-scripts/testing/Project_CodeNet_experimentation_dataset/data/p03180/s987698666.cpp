#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

ll dp[1<<20], cost[1<<20];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    vvll a(N, vll(N));
    rep(i, N) rep(j, N) cin >> a[i][j];

    rep(s, 1ll<<N) {
        rep(i, N) rep(j, N) {
            if(i >= j) continue;
            if(s>>i&1 && s>>j&1) cost[s] += a[i][j];
        }
    }

    rep(s, 1ll<<N) {
        for(ll t = s; t > 0; t = (t-1)&s) {
            chmax(dp[s], dp[s-t] + cost[t]);
        }
    }
    cout << dp[(1<<N)-1] << endl;
}
