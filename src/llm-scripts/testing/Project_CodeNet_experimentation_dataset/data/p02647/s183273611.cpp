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
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 2e5 + 5;
int n, k, a[N], cnt[N];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	fw (i, 0, n) cin >> a[i];
//	fw (i, 0, n) cout << a[i] << " "; cout << "\n";
	int steps = 0;
	fw (i, 0, k) {
		fw (j, 0, n) cnt[j] = 0;
		fw (j, 0, n) {
			cnt[max(0, j - a[j])]++;
			cnt[min(n, j + a[j] + 1)]--;
		}
		int tmp = 0;
		fw (j, 0, n) {
			tmp += cnt[j];
			a[j] = tmp;
		}
		
		bool done = 1;
		fw (j, 0, n) if (a[j] != n) done = 0;
		if (done) break;
	}
	fw (i, 0, n) cout << a[i] << " ";
	return 0;
}
