#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> s(n+1);
    rep(i, n) s[i+1] = (s[i]%m+a[i]%m)%m;
    map<int, int> mp;
    ll ans = 0;
    rep(i, n+1) {
        int num = s[i];
        int rem = num%m;
        ans += mp[rem];
        mp[rem]++;
        debug(i, num, rem, ans);
    }
    cout << ans << endl;
    // int db = 0;
    // rep(i, n) FOR(j, i, n) {
    //     ll tot = 0;
    //     FOR(k, i, j+1) tot += a[k];
    //     if (tot%m==0) {
    //         debug(i, j, tot);
    //         db++;
    //     }
    // }
    // debug(db);
}