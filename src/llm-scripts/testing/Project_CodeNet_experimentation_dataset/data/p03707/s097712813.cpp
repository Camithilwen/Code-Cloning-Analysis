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
#define ae(x) for(node *p = h[x]; p; p = p->nxt)
#define fill(x, k) memset(x, k, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
#define fio(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
template <class T> bool chkmin(T &x, T y)
{ return y < x ? (x = y , true) : false; }
template <class T> bool chkmax(T &x, T y)
{ return y > x ? (x = y , true) : false; }
void __init()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(16);
    srand(time(0) ^ ui(ul(new char)));
}
/* default code ends here */
const int maxn = 2e3 + 10;
int n, m, q;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
int main()
{
	__init();
	cin >> n >> m >> q;
	string foo;
	enum(i, 1, n)
	{
		cin >> foo;
		enum(j, 1, m)
			a[i][j] = foo[j - 1] - '0';
	}
	/*enum(i, 1, n)
	{
		enum(j, 1, m)
			cerr << a[i][j] << ' ';
		cerr << endl;
	}*/
	enum(i, 1, n)
		enum(j, 2, m)
			b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + bool(a[i][j] && a[i][j - 1]);
	/*enum(i, 1, n)
	{
		enum(j, 1, m)
			cerr << b[i][j] << ' ';
		cerr << endl;
	}*/
	enum(i, 2, n)
		enum(j, 1, m)
			c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + bool(a[i][j] && a[i - 1][j]);
	enum(i, 1, n)
		enum(j, 1, m)
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	int x1, y1, x2, y2;
	while(q --)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		//cerr << (a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]) << ' ' << (b[x2][y2] - b[x2][y1] - b[x1 - 1][y2] + b[x1 - 1][y1]) << ' ' << (c[x2][y2] - c[x2][y1 - 1] - c[x1][y2] + c[x1][y1 - 1]) << endl;
		cout << (a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]) - (b[x2][y2] - b[x2][y1] - b[x1 - 1][y2] + b[x1 - 1][y1]) - (c[x2][y2] - c[x2][y1 - 1] - c[x1][y2] + c[x1][y1 - 1]) << '\n';
	}
	return 0;
}
