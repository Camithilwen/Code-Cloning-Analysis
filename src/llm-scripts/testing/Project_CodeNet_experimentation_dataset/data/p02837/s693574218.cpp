#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)
ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
#define MAX_N 15
int A[MAX_N+1][MAX_N+1];
int main() {
	memset(A, -1, sizeof(A));
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int cnt; cin >> cnt;
		rep(j, cnt) {
			int tmp; cin >> tmp;
			cin >> A[i][tmp];
		}
	}
	int p = mod_pow(2, N, MOD);
	int ans = 0;
	for (int i = 1; i < p; i++) {
		int NG_flg = 0;
		for (int j = 0; (1 << j) < p; j++ ) {
			if (NG_flg == 1) break;
			if (!(i & (1 << j))) continue;
			for (int k = 1; k <= N; k++ ) {
				if (A[j+1][k] == -1) continue;
				if ( (A[j+1][k] == 1 && (i & (1 << (k-1))) == 0) ||
				     (A[j+1][k] == 0 && (i & (1 << (k-1))) > 0) ) {
					NG_flg = 1; break;
				}
			}
		}
		if (NG_flg == 0) {
			int cnt = 0;
			rep(j, 16) {
				if (i & (1 << j)) cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans << endl;
}