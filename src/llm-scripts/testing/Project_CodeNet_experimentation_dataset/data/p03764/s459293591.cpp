/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

ll x[maxn], y[maxn];
ll a[maxn], b[maxn];

ll sum(ll n) {
    return n * (n + 1) / 2 % Mod;
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &y[i]);
    for (int i = 1; i < n; i++) a[i] = (x[i + 1] - x[i] + Mod) % Mod;
    for (int i = 1; i < m; i++) b[i] = (y[i + 1] - y[i] + Mod) % Mod;
    n--, m--;
    ll X = 0, Y = 0;
    for (int i = 1; i <= n; i++) {
        ll cnt = sum(n) - sum(i - 1) - sum(n - i);
        cnt %= Mod;
        cnt = (cnt + Mod) % Mod;
        ll delta = cnt * a[i] % Mod;
        X = (X + delta) % Mod;
    }
    for (int i = 1; i <= m; i++) {
        ll cnt = sum(m) - sum(i - 1) - sum(m - i);
        cnt %= Mod;
        cnt = (cnt + Mod) % Mod;
        ll delta = cnt * b[i] % Mod;
        Y = (Y + delta) % Mod;
    }
    ll ans = X * Y % Mod;
    printf("%lld\n", ans);

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
