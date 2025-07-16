//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef long double ld ;

//#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define sz(a) (int)(a.size())
#define sg(a, b) (a + b - 1) / b

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000 + 10 ;
const int MAXN = 10000 + 10;
const int MLOG = 17;
const int NMAX = 20;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int m, n;
	cin >> n >> m;
	int A[MAXN], B[MAXN];
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < m; i++) cin >> B[i];
	sort(A, A + n, greater<int>());
	sort(B, B + m, greater<int>());
	int x = 0, y = 0, ans = 1;
	for(int i = n * m; i >= 1; i--) {
		if(A[x] == i && B[y] == i) {
			x++;
		   	y++;
		}else if(A[x] == i) {
			x++;
			ans = (ll)ans * y % MOD;
		}else if(B[y] == i) {
			y++;
			ans = (ll)ans * x % MOD;
		}else {
			ans = (ll)ans * max(0, x * y - n * m + i) % MOD;
		}
	}
	ans *= (x == n);
	ans *= (y == m);
	cout << ans;
}
