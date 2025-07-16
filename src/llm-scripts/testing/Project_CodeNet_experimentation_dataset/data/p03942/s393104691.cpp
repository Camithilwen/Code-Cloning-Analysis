#include <cstdio>
#include <algorithm>
using namespace std;
int n, ans, tot, to[1000005], u[1000005], v[1000005];
char S[1000005], T[1000005];
bool check(int x) {
	for (int i = 1; i <= tot - x; ++i)
		if (u[i + x] - x < v[i])
			return false;
	return true;
}
int main() {
    scanf("%d", &n);
    scanf("%s", S + 1);
    scanf("%s", T + 1);
	int ptr = n;
	for (int i = n; i >= 1; --i) {
		ptr = min(ptr, i);
		while (ptr > 0 && S[ptr] != T[i]) --ptr;
		if (ptr == 0) {
			puts("-1");
			return 0;
		}
		if (to[ptr] == 0) to[ptr] = i;
	}
	for (int i = 1; i <= n; ++i)
		if (to[i] != 0) {
			++tot;
			u[tot] = i;
			v[tot] = to[i];
		}
	int L = 0, R = n, mid;
	while (L < R) {
		mid = (L + R) >> 1;
		if (check(mid)) R = mid;
		else L = mid + 1;
	}
	printf("%d\n", R);
    return 0;
}
