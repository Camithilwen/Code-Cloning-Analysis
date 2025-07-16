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
typedef pair<ll, ll> P;
typedef vector<vector<P>> vvP;
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
    ll h, w;
    cin >> h >> w;

    vl a(h);
    set<ll> st1;
    vl v1(h*w+1);  // v1[i] : aの中でi以上の数の個数
    rep(i, h) {
        cin >> a[i];
        st1.insert(a[i]);
        v1[a[i]]++;
    }

    vl b(w);
    set<ll> st2;
    vl v2(h*w+1);  // v2[i] : bの中でi以上の数の個数
    rep(i, w) {
        cin >> b[i];
        st2.insert(b[i]);
        v2[b[i]]++;
    }

    if(st1.size() != h || st2.size() != w) {
        out(0);
        re0;
    }

    for(ll i = h*w; i >= 2; i--) {
        v1[i-1] += v1[i];
        v2[i-1] += v2[i];
    }   

    ll ans = 1;
    ll cnt = 0;
    for(ll x = h*w; x >= 1; x--) {
        if(st1.find(x) != st1.end() && st2.find(x) != st2.end()) {
            ans *= 1;
        }
        else if(st1.find(x) != st1.end() && st2.find(x) == st2.end()) {
            ans *= v2[x];
        }
        else if(st1.find(x) == st1.end() && st2.find(x) != st2.end()) {
            ans *= v1[x];
        }
        else {
            ans *= max(0LL, v1[x]*v2[x] - cnt);
        }
        ans %= mod;
        cnt++;
    }

    out(ans);
    re0;
}