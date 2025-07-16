#include <cstdio>
using namespace std;
#define MOD 1000000007
char s[200007];
int main(){
	register int n, n2, i, ans, cnt, pre, now;
	scanf("%d", &n);
	n2 = n * 2;
	scanf("%s", s + 1);
	if (s[1] == 'W' || s[n2] == 'W') {
		puts("0");
		return 0;
	}
	ans = cnt = 1, pre = 0;
	for (i = 2; i < n2; ++i) {
		if (s[i - 1] != s[i]) now = pre;
		else now = pre ^ 1;
		//now: 0 = [, 1 = ]
		if (now) {
			ans = 1ll * ans * cnt % MOD;
			--cnt;
		}
		else ++cnt;
		pre = now;
	}
	if (cnt > 1) {
		puts("0");
		return 0;
	}
	for (i = 2; i <= n; ++i) ans = 1ll * ans * i % MOD;
	printf("%d\n", cnt == 1 ? ans : 0);
	return 0;
}