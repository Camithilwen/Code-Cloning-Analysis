#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

int n,m;



int main()
{
    cin >> n >> m;
    vii a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    rep(i, n - 1)
    {
        if (a[i] == a[i + 1])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i, m - 1)
    {
        if (b[i] == b[i + 1])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    repr(now,n*m,0){
        int aidx = lower_bound(all(a), now) - a.begin();
        int bidx = lower_bound(all(b), now) - b.begin();
        ll atar = n - aidx, btar = m - bidx;
        ll kimeta = n * m  - now;
        if (a[aidx]==now && b[bidx]==now){
            continue;
        }
        else if(a[aidx]==now){
            ans = (ans * btar) % mod;
        }
        else if(b[bidx]==now){
            ans = (ans * atar) % mod;
        }
        else {
            ans = (ans * ((atar * btar) % mod + mod - kimeta) % mod) % mod;
        }
    }
    cout << ans << endl;
}
