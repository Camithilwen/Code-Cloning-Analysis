#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned ui;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<bool, bool> pbb;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define mid ((l + r) >> 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
#define enum(i, j, k) for(int i = j; i <= (k); i ++)
#define open(i, j, k) for(int i = j; i <  (k); i ++)
#define dec(i, j, k)  for(int i = j; i >= (k); i --)
#define fill(x, k) memset(x, k, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
#define fio(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
template <class T> bool chkmin(T &x, T y)
{ return y < x ? (x = y , true) : false; }
template <class T> bool chkmax(T &x, T y)
{ return y > x ? (x = y , true) : false; }
struct __init { __init()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cout.precision(16); cout << fixed;
	srand(time(0) ^ ui(ul(new char)));
}};
static __init __init__;
/* default code ends here */
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int n, m;
ll a[maxn], b[maxn];
int main()
{
	cin >> n >> m;
	enum(i, 1, n)
		cin >> a[i];
	enum(i, 1, m)
		cin >> b[i];
	ll s1 = 0, s2 = 0;
	enum(i, 1, n - 1)
		s1 = (s1 + (a[i + 1] - a[i]) * i % mod * (n - i)) % mod;
	enum(i, 1, m - 1)
		s2 = (s2 + (b[i + 1] - b[i]) * i % mod * (m - i)) % mod;
	cout << s1 * s2 % mod << '\n';
	return 0;
}
