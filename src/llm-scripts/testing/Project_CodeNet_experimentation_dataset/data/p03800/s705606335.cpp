# include <bits/stdc++.h>

# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n, m, k;
int a[N];
string s;

void sol (int x, int y) {
	for (int i = 1; i <= n; i ++) {
		a[i] = -1;
	}

	a[1] = x;
	a[2] = y;
	a[n+1] = x;
	for (int i = 2; i < n; i++) {
		bool nxt = 0; 
		if (a[i] == 1) nxt ^= 1;
		if (s[i] == 'x') nxt ^= 1;
		a[i+1] = (a[i-1] ^ nxt);
	}

	for (int i = 1; i <= n; i ++) {
		int l = i-1;
		int r = i+1;
		if (r > n) r = 1;
		if (l < 1) l = n;

		bool nxt = 0; 
		if (a[i] == 1) nxt ^= 1;
		if (s[i] == 'x') nxt ^= 1;

		if(!nxt) {
			if (a[l] != a[r]) return;
		} else {
			if (a[l] == a[r]) return;
		} 

	}

	for (int i = 1; i <= n; i ++)
		cout << (a[i] ? "W" : "S");
	exit(0);
}

int main () {
	SpeedForce;
	cin >> n >> s;
	s = '#' + s;


	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 2; b++) {
			sol(a, b);
		}
	}

	puts("-1");

   	return Accepted;
}

// B...a
