#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; ++i)
#define per(i, j, k) for (int i = j; i >= k; --i)
#define int long long
using namespace std;

const int N = 1000001;
int a[N], sum[N];

inline int read() {
	int x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * flag;
}

int Abs(int x) {return x < 0 ? -x : x;}

signed main() {
	int n = read();
	rep(i, 1, n) {
		a[i] = read();
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 1e18, s1 = a[1], s2 = a[2], s3 = a[3], s4 = sum[n] - sum[3], l = 2, r = 4;
	rep(i, 3, n) {
		while (l < i && Abs(s1 - s2) > Abs(s1 + a[l] - s2 + a[l])) {
			s1 += a[l];
			s2 -= a[l];
			l++;
		}
		while (r <= n && Abs (s3 - s4) > Abs(s3 + a[r] - s4 + a[r])) {
			s3 += a[r];
			s4 -= a[r];
			r++;
		}
		int mn = min(s1, min(s2, min(s3, s4)));
		int mx = max(s1, max(s2, max(s3, s4)));
		ans = min(ans, mx - mn);
		s2 += a[i];
		s3 -= a[i];
//		printf("%d %d %d %d %d %d %d\n", s1, s2, s3, s4, mn, mx, ans);
	}
	printf("%lld\n", ans);
	return 0;
}