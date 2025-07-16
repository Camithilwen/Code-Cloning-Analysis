#include <bits/stdc++.h>
#define pb push_back
#define vii vector<int>
#define task "KMULT"
#define pll pair<ll, ll>
#define pii pair< ll, pair< ll, ll > >
#define fi first
#define se second

using ll = long long;
using ld = long double;
using ull = unsigned long long;
const ll mod = 998244353;
using namespace std;
const int N = 6e5+5;
ll m, n, k, t, T, ans, u, v, tong;
ll a[N], b[N], st[N*4], lazy[N*4];
string s;
vector<ll> kq;
struct dang
{
    ll l, r, pos;
} p[N];
bool cmp(const dang& X, const dang& Y)
{
    return (X.r < Y.r) || (X.r == Y.r && X.l < Y.l);
}
void sol()
{
    cin >> n;
    pll q;
    for(int i = 1; i <= n; i ++)
    {
        cin >> p[i].l >> p[i].r;
        if(p[i].l > q.fi)
        {
            q.fi = p[i].l;
            q.se = p[i].r;
        }
        else if(p[i].l == q.fi && p[i].r > q.se)q.se = p[i].r;
    }
    sort(p+1, p+1+n, cmp);
    ans = p[1].r - p[1].l + 1;
    for(int i = 1; i <= n; i ++)a[i] = max(a[i-1], p[i].l);
    for(int i = 2; i <= n; i ++)
    {
        if(p[i].r <= q.se)
        {
            ans = max(ans, max((ll)0, p[i].r - q.fi + 1) + max((ll)0, p[1].r - a[i-1] +1 ) );
        }
        if(p[i].l != q.fi || p[i].r != q.se)ans = max(ans, max(p[1].r - q.fi + 1, (ll)0) + p[i].r - p[i].l + 1);
    }
    cout << ans;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(task".INP", "r"))
    {
		freopen(task".INP","r",stdin);
		freopen(task".OUT","w",stdout);
    }
    sol();
    //cout << chap(4, 3);
}
