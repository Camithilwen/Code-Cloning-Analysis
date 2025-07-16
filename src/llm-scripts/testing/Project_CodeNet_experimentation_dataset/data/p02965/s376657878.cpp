#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;

inline int add(int x, int y)
{
	if (x + y < mod)
		return x + y;
	return x + y - mod;
}

inline int sub(int x, int y)
{
	if (x >= y)
		return x - y;
	return x - y + mod;
}

inline int mult(int x, int y)
{
	return x * (LL) y % mod;
}

inline int power(int x, int y)
{
	int r = 1;
	while(y)
	{
		if (y & 1)
			r = mult(r, x);
		x = mult(x, x);
		y >>= 1;
	}
	
	return r;
}

inline int inverse(int x)
{
	return power(x, mod - 2);
}

const int N = 1 << 22;
int f[N];
int inv[N];

inline int C(int n, int m)
{
	int res = f[n];
	res = mult(res, inv[m]);
	res = mult(res, inv[n - m]);
	return res;
}

inline int count(int n, int m)
{
	return C(n - 1 + m, m);
}

int jebu(int n, int odd, int m)
{
	return count(n, (3 * m - odd) / 2);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	f[0] = 1;
	FOR(i, 1, N)
		f[i] = mult(f[i - 1], i);
	FOR(i, 0, N)
		inv[i] = inverse(f[i]);
		
	int ans = count(n, 3 * m);
	int tut = 0;
	FOR(i, 2 * m + 1, 3 * m + 1)
		tut = add(tut, count(n - 1, 3 * m - i));
		
	tut = mult(tut, n);	
	ans = sub(ans, tut); 
	
	int odd = 0;
	for(int cnt = m + 2; cnt <= n && cnt <= 3 * m; cnt += 2)
	{
		int coef = C(n, cnt);
		int here = jebu(n, cnt, m);	
		odd = add(odd, mult(coef, here));
	}
	
	ans = sub(ans, odd);
	cout << ans << endl;
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}
