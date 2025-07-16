#include <cstdio>

const int maxn = 1e6 + 10;

int n, fnt, rar, q[maxn], ans, i, j;
char s[maxn], t[maxn];

int main() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	j = 1;
	for (i = 1; i <= n; ++i) {
		if(s[i] != t[i]) {
			j = 0;
			break;
		}
	}
	if(j) {
		return !puts("0");
	}
	j = n + 1;
	for (i = n; i; --i) {
		if(!(j - 1 >= i && t[j - 1] == s[i])) {
			continue;
		}
		while(j - 1 >= i && t[j - 1] == s[i]) {
			--j;
		}
		while(fnt < rar && q[fnt] - rar + fnt >= j) {
			++fnt;
		}
		if(i < j) {
			q[rar++] = i;
			(rar - fnt > ans) && (ans = rar - fnt);
		}
	}
	return !printf("%d\n", j == 1 ? ans + 1 : -1);
}