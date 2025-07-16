#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 505;
const int P = 8005;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

int n, pr[P], pcnt, vis[P];
LL a[N][N], mx;
//set<LL> S;

LL gcd(LL x, LL y) {
	return (!y)? x : gcd(y, x % y);
}

inline LL lcm(LL x, LL y) {
	if (!x || !y) return x + y;
	return x / gcd(x, y) * y;
}

void init() {
	read(n);
	if (n == 2) {
		printf("4 7\n23 10\n");
		exit(0);
	}
	for (int i = 2; i <= 8000; ++i) {
		if (!vis[i]) {
			pr[++pcnt] = i;
		}
		for (int j = 1; j <= pcnt && i * pr[j] <= 8000; ++j) {
			vis[i * pr[j]] = 1;
			if (i % pr[j]) continue;
		}
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!((i + j) & 1)) {
				a[i][j] = pr[(i + j) / 2] * pr[(n - i + 1 + j) / 2 + n / 2];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((i + j) & 1) {
				a[i][j] = lcm(lcm(a[i - 1][j], a[i + 1][j]), lcm(a[i][j - 1], a[i][j + 1])) + 1;
			}
			printf("%lld ", a[i][j]);
/*mx = max(mx, a[i][j]);
if (S.find(a[i][j]) != S.end()) {
	printf("error\n");
}
S.insert(a[i][j]);*/
		}
		printf("\n");
	}
//printf("%lld\n", mx);
}

int main() {
	init();
	solve();
	return 0;
}
