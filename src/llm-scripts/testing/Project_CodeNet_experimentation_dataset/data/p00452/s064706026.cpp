#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, c[1009], s[510009], t[510009], cnt[32777], sum[32777];
int main() {
	while (scanf("%d%d", &n, &m), n) {
		for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
		sort(c, c + n);
		int b = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = i; j <= n && c[i] + c[j] <= m; j++) {
				s[b++] = c[i] + c[j];
			}
		}
		for (int i = 0; i < 30; i += 15) {
			fill(cnt, cnt + 32768, 0); sum[0] = 0;
			for (int j = 0; j < b; j++) cnt[(s[j] >> i) & 32767]++;
			for (int j = 0; j < 32768; j++) sum[j + 1] = sum[j] + cnt[j];
			for (int j = 0; j < b; j++) t[sum[(s[j] >> i) & 32767]++] = s[j];
			for (int j = 0; j < b; j++) s[j] = t[j];
		}
		int r = b - 1, ret = 0;
		for (int i = 0; i < b && i <= r; i++) {
			while (r > 0 && s[i] + s[r] > m) r--;
			ret = max(ret, s[i] + s[r]);
		}
		printf("%d\n", ret);
	}
	return 0;
}