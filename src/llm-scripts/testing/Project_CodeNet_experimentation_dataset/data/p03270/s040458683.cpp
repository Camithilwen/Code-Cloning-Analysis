#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 998244353, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 4005;
int n, k, fac[N], ifac[N];
void add(int &x, int y) {
	x += y; if (x >= mod) x -= mod;
}
void rem(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
int fpow(int a, int p) {
	if (!p) return 1;
	int tmp = fpow(a, p >> 1);
	tmp = mul(tmp, tmp);
	if (p & 1) tmp = mul(tmp, a);
	return tmp;
}
int inv(int a) {
	return fpow(a, mod - 2);
}
int C(int n, int k) {
	if (n < k || k < 0) return 0;
	return mul(fac[n], mul(ifac[k], ifac[n - k]));
}
int solve(int i, int tot) {
	int special = 0, vari = 0;
	fw (j, 1, k + 1) {
		int other = i - j;
		if (other > 0 && other <= k) {
			if (j < other) special++, vari++;
		} else vari++;
	}
	int ans = 0, curPow = 1;
	fw (j, 0, special + 1) {
		int cntWays = C(special, j);
		int cntLeft = vari - special;
		add(ans, mul(mul(cntWays, curPow), C(tot + cntLeft - 1, j + cntLeft - 1)));
		
		curPow = mul(curPow, 2);
	}
	return ans;
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fac[0] = ifac[0] = 1;
	fw (i, 1, N) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		ifac[i] = inv(fac[i]);
	}
	cin >> k >> n;
	fw (i, 2, 2 * k + 1) {
		int ans = 0;
		if (i & 1) {
			add(ans, solve(i, n));
		} else {
			fw (haveHalf, 0, 2) add(ans, solve(i, n - haveHalf));
		}
		cout << ans << "\n";
	}
	return 0;
}