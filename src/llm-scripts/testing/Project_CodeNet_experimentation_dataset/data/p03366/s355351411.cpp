#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int x[N];
LL w[N];
int S, n;

int main() {

	scanf("%d%d", &n, &S);
	For(i, 1, n) scanf("%d%lld", &x[i], &w[i]);

	int l = 1, r = n, nxt = 0;
	LL ans = 0;
	while (x[l] < S && x[r] > S) {
		if (w[l] >= w[r]) {
			w[l] += w[r];
			if (nxt != l) ans += x[r] - x[l];
			--r, nxt = l;
		} else {
			w[r] += w[l];
			if (nxt != r) ans += x[r] - x[l];
			++l, nxt = r;
		}
	}

	if (x[l] < S) ans += S - x[l];
	else ans += x[r] - S;
	printf("%lld\n", ans);

	return 0;
}