#include <bits/stdc++.h>
using namespace std;
#pragma region
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << (#x) << "] = [", _print(x)
#else
#define debug(x...)
#endif
#pragma endregion
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(v) int((v).size())
#define int ll
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back

int MOD = 998244353;
int fact[222'222];
int power(int a, int n)
{
    int res = 1;
    int now = a;
    while(n)
    {
        if (n&1)
        {
            res  = (res*now) %MOD;
        }
        n>>=1;
        now = (now*now)%MOD;
    }
    return res;
}
int inv(int a)
{
    return power(a, MOD-2);
}
int C(int n, int r)
{
    if (n < r) return 0;
    return fact[n] %MOD * inv(fact[n-r])%MOD * inv(fact[r])%MOD;
}
int n, m, k;
int f(int p)
{
    return m * power(m-1, n-1-p)%MOD*C(n-1,p)%MOD;
}
void solve()
{
    fact[0] = 1;
    forn(i, 222'222-1) fact[i+1] = fact[i] * (i+1)%MOD;
    cin>>n>>m>>k;
    int ans = 0;
    forn(i, k+1)
    {
        ans =(ans + f(i))%MOD;
    }
    cout << ans <<'\n';
}


signed main()
{
    int T = 1;
    ios_base::sync_with_stdio(0); cin.tie(0);
    //cin >> T;
    for(int i=1;i<=T;++i)
    {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}