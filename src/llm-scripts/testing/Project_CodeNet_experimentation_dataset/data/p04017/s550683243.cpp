#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ii = pair<int, int>;
 
void solve();
 
clock_t start_time;
double get_current_time() {
	return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}
 
int main() {
	// freopen("input.txt", "r", stdin);
	// freopen();

	ios_base::sync_with_stdio(false);
	solve();
}
 
/* ========== actual code starts here ========== */
 
#define fi first
#define re return
#define se second
#define in insert
#define pb push_back
#define eb emplace_back
#define y1 y123123123123
#define all(x) x.begin(), x.end()
#define hash hash123s
 
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repx(i, x, n) for (int i = x; i < (n); i++)
#define repd(i, n, d) for (int i = 0; i < (n); i += d)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepd(i, n, d) for (int i = (n) - 1; i >= 0; i -= d)
 
#ifdef artem
	#define debug(x) x
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define debug(x)
#endif

const int limit = 100500;
const int k = 18;
const int inf = 10050000;

int n, l;
int x[ limit ];
int dp[ limit ][ k + 1 ];

void precalc() {
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j < n && x[ j ] - x[ i ] <= l) {
			++j;
		}
		dp[ i ][ 0 ] = j - 1;
	}
	dp[ n - 1 ][ 0 ] = n - 1;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 1; j <= k; j++) {
			dp[ i ][ j ] = dp[ dp[ i ][ j - 1 ] ][ j - 1 ];
		}
	}

	// for(int i = 0; i <= k; i++) {
	// 	for(int j = 0; j < n; j++) {
	// 		cout << dp[ j ][ i ] << ' ';
	// 	}
	// 	cout << endl;
	// }
}

int calc(int l, int r) {
	int ans = 0;
	for(int j = k; j >= 0; j--) {
		if(dp[ l ][ j ] < r) {
			l = dp[ l ][ j ];
			ans += (1 << j);
		}
	}
	re ans + 1;
}

void solve() {
	cin >> n;
	rep(i, n) {
		cin >> x[ i ];
	}
	cin >> l;

	precalc();
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		if(l > r) swap(l, r);
		cout << calc(l, r) << '\n';
	}
}