#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000005;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

int n;
char s[maxn], t[maxn];
int ans, l, r, q[maxn];

int main()
{
	scanf("%d\n%s%s", &n, s + 1, t + 1);

	int i;
	for (i = 1; i <= n; ++i)
		if (s[i] != t[i]) break;
	if (i > n) return puts("0"), 0;
	
	int up = n, down = n;
	l = 1; r = 0;
	while (down) {
		while (down && t[down - 1] == t[down]) --down;
		while (up && (up > down || s[up] != t[down])) --up;
		if (!up) return puts("-1"), 0;
		while (l < r && q[l] - (r - l + 1) >= down) ++l;
		if (up != down) q[++r] = up;
		ans = max(ans, r - l + 2);
		--down;
	}

	printf("%d\n", ans);
	
	return 0;
}
