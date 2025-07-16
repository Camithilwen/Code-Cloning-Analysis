#include <bits/stdc++.h>
using namespace std;

inline int gi()
{
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	int sum = 0;
	while('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

typedef long long ll;
const int maxn = 100005;

int n, s, x[maxn];
ll ans, p[maxn];


int main()
{
	n = gi(); s = gi();
	for (int i = 1; i <= n; ++i) x[i] = gi(), p[i] = gi();

	int l = 1, r = n, d = p[1] >= p[n];
	while (1) {
		if (x[l] >= s) {ans += x[r] - s; break;}
		if (x[r] <= s) {ans += s - x[l]; break;}
		if (p[l] >= p[r]) {
			if (d != 0) {ans += x[r] - x[l]; d ^= 1;}
			p[l] += p[r--];
		} else {
			if (d != 1) {ans += x[r] - x[l]; d ^= 1;}
			p[r] += p[l++];
		}
	}

	printf("%lld\n", ans);
	
	return 0;
}

