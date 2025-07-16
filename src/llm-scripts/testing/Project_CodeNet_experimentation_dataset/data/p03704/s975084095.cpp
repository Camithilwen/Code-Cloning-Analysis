#include <bits/stdc++.h>
using namespace std;

long long get_rev(long long x) {
	long long nx = 0;
	while (x) nx = nx * 10 + x % 10, x /= 10;
	return nx;
}

long long get_rev(long long x, int len) {
	long long nx = 0;
	while (len--) nx = nx * 10 + x % 10, x /= 10;
	return nx;
}

int cnt;

long long solve(long long d, long long len) {
	long long tmp = len >> 1, pw = 1;
	while (tmp--) pw *= 10;
	long long ans = 0;
	for (int i = 0; i < pw; i++) {
		long long tmp = (d + i) % pw;
		tmp = get_rev(tmp, len >> 1);
		if (len & 1) tmp = tmp * 10;
		long long n = tmp * pw + i;
		if ((cnt ? get_rev(n, len) : get_rev(n)) == n + d) ans++;
	}
	if (len & 1) ans *= 10;
	return ans;
}

int main () {
	int d; cin >> d;
	cnt = 0;
	while (d % 10 == 0) d /= 10, cnt++;
	int len = 0, D = d;
	while (D) len++, D /= 10;
	long long ans = solve(d, len) + solve(d, len + 1) + solve(d, len + 2) + solve(d, len + 3) + solve(d, len + 4) + solve(d, len + 5) + solve(d, len + 6);
	if (cnt) cnt--, ans *= 9;
	while (cnt--) ans *= 10;
	cout << ans << endl;
	return 0;
}
