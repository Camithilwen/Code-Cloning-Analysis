#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 100010
int n, k, a[MAXN];
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int g;; k ^= 1) {
		int count = 0;
		for (int i = 1; i <= n; i++) count += a[i] & 1;
		if ((n - count) & 1) {
			return puts(k ? "Second" : "First"), 0;
		}
		if (count >= 2) {
			return puts(k ? "First" : "Second"), 0;
		}
		g = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] & 1) {
				if (a[i] == 1) return puts(k ? "First" : "Second"), 0;
				--a[i];
			}
			g = gcd(a[i], g);
		}
		for (int i = 1; i <= n; i++) a[i] /= g;
	}
	return 0;
}