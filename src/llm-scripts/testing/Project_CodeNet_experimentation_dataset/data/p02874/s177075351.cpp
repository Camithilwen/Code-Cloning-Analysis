#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pair<ll, ll>>> vvpll;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n;
    cin >> n;
 
    vl L(n), R(n);
    ll p = 0, q = 0;  // L[p]はLの最大値で、R[q]はRの最小値
    ll MAXL = 0, MINR = INF;
    rep(i, n) {
        cin >> L[i] >> R[i];
        R[i]++;
        if(MAXL < L[i]) {
            MAXL = L[i];
            p = i;
        }
        if(MINR > R[i]) {
            MINR = R[i];
            q = i;
        }
    }
 
    ll ans = 0;
    // 区間pと区間qを同じ集合に入れる場合
    rep(i, n) {
        if(i == p || i == q) {
            continue;
        }
        chmax(ans, max(0LL, R[q] - L[p]) + R[i] - L[i]);
    }
 
    // 区間pと区間qを違う集合に入れる場合
    vector<pair<ll, ll>> c(n);
    rep(i, n) {
        ll a = max(0LL, R[i] - L[p]);
        ll b = max(0LL, R[q] - L[i]);
        c[i] = make_pair(a, -b);
    }
    sort(all(c));
    ll u = abs(c[0].second);
    exrep(i, 1, n-1) {
        chmax(ans, c[i].first + u);
        chmin(u, abs(c[i].second));
    }
 
    out(ans);
    re0;
}