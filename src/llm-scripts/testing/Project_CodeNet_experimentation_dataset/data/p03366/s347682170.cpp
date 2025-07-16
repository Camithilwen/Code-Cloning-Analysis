#include <bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;
#define int long long
#define debug printf("fuck %d\n", __LINE__);

inline LL read() {
	LL res = 0, bo = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') bo = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		res = (res << 1) + (res << 3) + ch - '0';
		ch = getchar();
	}
	return bo * res;
}

template <typename T>
void read(T &x) {
	x = read();
}

template <typename T, typename... Argv>
void read(T &a, Argv &... argv) {
	read(a);
	read(argv...);
}

const int N = 1e5 + 10;
int x[N], p[N], s, n;

LL Calc(int l, int r, int t) {
	if (s < x[l]) return x[r] - s;
	if (s > x[r]) return s - x[l];
	if (p[l] >= p[r]) return p[l] += p[r], Calc(l, r - 1, l) + (t == r ? x[r] - x[l] : 0);
	else return p[r] += p[l], Calc(l + 1, r, r) + (t == l ? x[r] - x[l] : 0);
}

signed main() {
	read(n, s);
	for (int i = 1; i <= n; ++ i) read(x[i], p[i]);
	std::cout << Calc(1, n, p[n] > p[1] ? 1 : n) << std::endl;
	return 0;
}