#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 90;

int n, a[3][N], c[N], p[N], m, S, t[N * 3], bl[N * 3];
bool r[N];

void Ji (bool x) { if (!x) puts("No"), exit(0); }

bool Pd () {
	bool ret = 0;
	for (int i = 1; i <= S; ++i) t[i] = 0;
	for (int i = 1; i <= m; ++i) ++t[p[i]];
	for (int i = 1, j = 0; i <= S; ++i) if (t[i]) bl[i] = ++j;
	for (int i = 1; i <= m; ++i) while (i != bl[p[i]]) std :: swap(p[i], p[bl[p[i]]]), ret ^= 1;
	return ret;
}

int main () {
	scanf("%d", &n); S = 3 * n;
	for (int i = 0; i < 3; ++i) for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i) {
		if (a[0][i] > a[1][i]) {
			Ji(a[0][i] == a[1][i] + 1);
			Ji(a[1][i] == a[2][i] + 1);
			Ji(a[1][i] % 3 == 2);
			c[i] = a[1][i] / 3;
			Ji((c[i] ^ i) & 1);
			++c[i];
			r[i & 1] ^= 1;
		} else {
			Ji(a[0][i] + 1 == a[1][i]);
			Ji(a[1][i] + 1 == a[2][i]);
			Ji(a[1][i] % 3 == 2);
			c[i] = a[1][i] / 3;
			Ji((c[i] ^ i) & 1);
			++c[i];
		}
	}
	for (int i = 1; i <= n; ++i, ++i) p[++m] = c[i];
	Ji(Pd() == r[0]); m = 0;
	for (int i = 2; i <= n; ++i, ++i) p[++m] = c[i];
	Ji(Pd() == r[1]);
	puts("Yes");
	return 0;
}