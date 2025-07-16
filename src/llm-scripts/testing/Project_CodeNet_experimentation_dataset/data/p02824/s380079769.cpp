#include <cstdio>
#include <algorithm>

const int N = 100000;
int n, m, v, p, a[N];

bool test(int t) 
{
	t = n - t;
	int amt = v - t - 1;
	int i;
	for (i = n - 1; a[t] + m < a[i]; --i, --amt);
	long long to = 0;
	for (int j = i; j > t; --j) to += a[t] + m - a[j];
	for (; i > t && to < (long long)amt * m; --i) {
		--amt;
		to -= a[t] + m - a[i];
	}
	return n - i <= p;
}

int main() 
{
	scanf("%d%d%d%d", &n, &m, &v, &p);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	std::sort(a, a + n);
	int l = p, r = n;
	int ans;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (test(m)) {
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	printf("%d\n", ans);
	return 0;
}
