#include <bits/stdc++.h>
#define trans(x) add(nxt[ d[i][x] ], cur[i])

const int N = 300054, mod = 1000000007;
const int d[8][2] = {{2, 3}, {6, 6}, {4, 5}, {6, 7}, {2, 2}, {2, 3}, {1, 3}, {7, 7}};

int dp_[2][8], *cur = *dp_, *nxt = dp_[1];
char s[N];

inline int & add(int &x, const int y) {return x += y - mod, x += x >> 31 & mod;}

int main() {
	int i, ans; char *p = s; *nxt = 1;
	for (scanf("%s", s); *p; ++p) {
		std::swap(cur, nxt), memset(nxt, 0, sizeof *dp_);
		for (i = 0; i < 8; ++i) *p == 48 || trans(1), *p == 49 || trans(0);
	}
	printf("%d\n", add(ans = nxt[3], nxt[7]));
	return 0;
}