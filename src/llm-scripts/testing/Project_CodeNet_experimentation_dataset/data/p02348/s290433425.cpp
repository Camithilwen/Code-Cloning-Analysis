#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int N, Q;
int main() {
	scanf("%d%d", &N, &Q);
	vector<int> tp(Q), s(Q), t(Q), x(Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &tp[i], &s[i]);
		if (tp[i] == 0) scanf("%d%d", &t[i], &x[i]), t[i]++;
	}
	vector<int> d(N, 2147483647);
	int B = sqrt(Q);
	for (int i = 0; i < B; i++) {
		int l = 1LL * i * Q / B, r = 1LL * (i + 1) * Q / B;
		for (int j = l; j < r; j++) {
			if (tp[j] == 1) {
				bool flag = false;
				for (int k = j - 1; k >= l; k--) {
					if (tp[k] == 0 && s[k] <= s[j] && s[j] < t[k]) {
						printf("%d\n", x[k]); flag = true;
						break;
					}
				}
				if (!flag) printf("%d\n", d[s[j]]);
			}
		}
		vector<int> cp = { 0, N };
		for (int j = l; j < r; j++) {
			if (tp[j] == 0) {
				cp.push_back(s[j]);
				cp.push_back(t[j]);
			}
		}
		sort(cp.begin(), cp.end());
		cp.erase(unique(cp.begin(), cp.end()), cp.end());
		vector<int> f(cp.size() - 1, -1);
		for (int j = l; j < r; j++) {
			if (tp[j] == 0) {
				int pl = lower_bound(cp.begin(), cp.end(), s[j]) - cp.begin();
				int pr = lower_bound(cp.begin(), cp.end(), t[j]) - cp.begin();
				for (int k = pl; k < pr; k++) f[k] = x[j];
			}
		}
		for (int j = 0; j < cp.size() - 1; j++) {
			if (f[j] != -1) {
				for (int k = cp[j]; k < cp[j + 1]; k++) d[k] = f[j];
			}
		}
	}
	return 0;
}