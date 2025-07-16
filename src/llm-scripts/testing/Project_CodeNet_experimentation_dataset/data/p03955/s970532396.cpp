#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int mat[4][N], val[N], n, num[2], v[N];
void add(int x, int val) {
	for (; x <= n; x += ((x) & (-(x))))
		v[x] += val;
}
int query(int x) {
	int ret = 0;
	for (; x; x -= ((x) & (-(x))))
		ret += v[x];
	return ret;
}
void fail() {
	puts("No");
	exit(0);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &mat[i][j]);
	for (int i = 1; i <= n; ++i) {
		if (mat[1][i] % 3 == 0) {
			if (mat[2][i] == mat[1][i] - 1 && mat[3][i] == mat[1][i] - 2)
				val[i] = -mat[1][i] / 3;
			else fail();
		}
		else if (mat[3][i] % 3 == 0) {
			if (mat[2][i] == mat[3][i] - 1 && mat[1][i] == mat[3][i] - 2)
				val[i] = mat[3][i] / 3;
			else fail();
		}
		else fail();
	}
	for (int i = 1; i <= n; i += 2) {
		if (val[i] < 0) num[1] ^= 1, val[i] = -val[i];
		if (val[i] % 2 == 0) fail();
	}
	for (int i = 2; i <= n; i += 2) {
		if (val[i] < 0) num[0] ^= 1, val[i] = -val[i];
		if (val[i] & 1) fail();
	}
	for (int i = 1; i <= n; i += 2) {
		if ((query(n) - query(val[i])) & 1) num[0] ^= 1;
		add(val[i], 1);
	}
	memset(v, 0, sizeof v);
	for (int i = 2; i <= n; i += 2) {
		if ((query(n) - query(val[i])) & 1) num[1] ^= 1;
		add(val[i], 1);
	}
	if ((!num[0]) && (!num[1]))
		puts("Yes");
	else puts("No");
	return 0;
}