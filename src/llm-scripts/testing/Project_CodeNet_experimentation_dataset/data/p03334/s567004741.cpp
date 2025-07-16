#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
const int N = 605;

inline int input() {
	int x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

inline void chkmin(int &x, int y) { x = x < y ? x : y; }
template <class T> T sqr(T x) { return x * x; }

int n, m, D1, D2;
int ansx[N * N], ansy[N * N], tot;
bool col[N][N];

void work(int D) {
	int tmp = 0;
	while(D % 4 == 0) D >>= 2, ++tmp;
	if (D % 4 == 3) return void();
	if (D % 4 == 1) {
		for (int x = 0; x <= n; ++x)
			for (int y = 0; y <= n; ++y)
				if (((x >> tmp) + (y >> tmp)) & 1) col[x][y] = true;
	}
	if (D % 4 == 2) {
		for (int x = 0; x <= n; ++x)
			for (int y = 0; y <= n; ++y)
				if ((x >> tmp) & 1) col[x][y] = true;
	}
}

int main() {
#ifdef local
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
//	freopen("log", "w", stderr);
#endif
	ios::sync_with_stdio(false);

	cin >> n >> D1 >> D2;
	m = n, n = n * 2 - 1;

	work(D1), work(D2);

	for (int x = 0; x <= n; ++x)
		for (int y = 0; y <= n; ++y) {
			if (!col[x][y]) ansx[++tot] = x, ansy[tot] = y;
			if (tot == m * m) goto Get;
		}
Get:;

	for (int i = 1; i <= tot; ++i)
		printf("%d %d\n", ansx[i], ansy[i]);
	return 0;
}