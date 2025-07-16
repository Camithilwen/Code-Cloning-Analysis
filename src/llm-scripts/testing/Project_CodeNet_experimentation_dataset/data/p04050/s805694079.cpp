#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Forr(i, j, k) for (int i = j; i >= k; -- i)

using namespace std;

inline int read() {
	int x = 0, p = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') p = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x * p;
}

inline void File() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
}

const int N = 1e2 + 10;
int a[N], sta[N], tp, n, m, lst, sum, cnt, ans[N];

int main() {

	n = read(), m = read();
	For(i, 1, m) {
		a[i] = read();
		if (a[i] & 1) sta[++ tp] = i;
	}

	if (tp > 2) return puts("Impossible"), 0;

	if (tp > 0) swap(a[1], a[sta[1]]);
	if (tp > 1) swap(a[m], a[sta[2]]);


	if (m == 1) {
		if (a[1] == 1) return printf("1\n1\n1\n"), 0;
		return printf("%d\n2\n%d %d\n", a[1], a[1] - 1, 1), 0;
	}
	For(i, 1, m) printf("%d ", a[i]); puts("");

	ans[cnt = 1] = lst = a[1] - 1; sum = 1;
	For(i, 1, m) sum += a[i], ans[++ cnt] = sum - lst, lst = sum;
	ans[cnt] -= 1;

	int tt = 0; For(i, 1, cnt) if (ans[i] == 0) ++ tt;		

	printf("%d\n", cnt - tt);
	For(i, 1, cnt) if (ans[i]) printf("%d ", ans[i]); puts("");

	return 0;
}
