#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cctype>
#include <string>
#include <numeric>
#include <cstring>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std ;
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (a); i >= (b); --i)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (register int i = head[x]; i; i = edge[i].nex)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, cnt) memset(a, cnt, sizeof(a))
#define cop(a, b) memcpy(a, b, sizeof(a))
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define SC(t, x) static_cast <t> (x)
#define ub upper_bound
#define lb lower_bound
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define y1 y1_
#define Pi acos(-1.0)
#define iv inline void
#define enter putchar('\n')
#define siz(x) ((int)x.size())
#define file(x) freopen(x".in", "r", stdin),freopen(x".out", "w", stdout)
typedef double db ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <int, int> pii ;
typedef vector <int> vi ;
typedef vector <pii> vii ;
typedef queue <int> qi ;
typedef queue <pii> qii ;
typedef set <int> si ;
typedef map <int, int> mii ;
typedef map <string, int> msi ;
const int maxn = 1e6 + 100 ;
const int inf = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const ll mod = 1e9 + 7 ;
const double eps = 1e-5 ;

ll n, s;

ll x[maxn], p[maxn];

ll ans[maxn], tim;

signed main()
{
	scanf("%lld %lld", &n, &s);
	rep(i, 1, n) scanf("%lld %lld", &x[i], &p[i]);
	ll l = 1, r = n;
	rep(i, 1, n)
	{
		if(x[r] < s) ans[i] = x[l], p[r] += p[l ++];
		else if(x[l] > s) ans[i] = x[r], p[l] += p[r --];
		else
		{
			if(p[l] < p[r]) ans[i] = x[l], p[r] += p[l ++];
			else ans[i] = x[r], p[l] += p[r --];
		}
	}
	per(i, n, 1) tim += abs(s - ans[i]), s = ans[i];
	printf("%lld\n", tim);
	return 0;
}