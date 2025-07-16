#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
 
template <typename T1, typename T2> bool chkmin(T1 &x, T2 y) { return y < x ? (x = y, true) : false; }
template <typename T1, typename T2> bool chkmax(T1 &x, T2 y) { return y > x ? (x = y, true) : false; }

const int MOD = 1e9 + 7;
int add(int x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}
int sub(int x, int y)
{
    x -= y;
    if (x < 0) x += MOD;
    return x;
}
int mult(int x, int y)
{
    return x * (ll)y % MOD;
}
int bpow(int x, ll y)
{
    int res = 1;
    for (; y; y >>= 1)
    {
        if (y & 1)
        {
            res = mult(res, x);
        }
        x = mult(x, x);
    }
    return res;
}
int rev(int x)
{
    return bpow(x, MOD - 2);
}

const int N = 300005;
int fact[N], rfact[N];

int cnk(int n, int k)
{
    if (k > n)
        return 0;
    return mult(fact[n], mult(rfact[k], rfact[n - k]));
}

int grid(int n, int m)
{
    return cnk(n - 1 + m - 1, n - 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif

    fact[0] = rfact[0] = fact[1] = rfact[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        fact[i] = mult(fact[i - 1], i);
        rfact[i] = rev(fact[i]);
    }
    
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    int sum = 0;
    for (int i = 0; i < H - A; ++i)
    {
        sum = add(sum, mult(grid(B, i + 1), grid(H - i, W - B)));
    }
    cout << sum << '\n';

    return 0;
}

