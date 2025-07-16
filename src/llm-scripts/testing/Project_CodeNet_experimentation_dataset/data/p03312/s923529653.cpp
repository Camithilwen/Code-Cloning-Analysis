#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int n, a[maxn];
long long sum[maxn];

long long F(int left, int m, int right) {
	return abs(sum[right]-2*sum[m]+sum[left]);
}

int find(int l, int r) {
	int left = l-1, right = r+1;
	while (r-l >= 3) {
		int m1 = l + (r-l)/3;
		int m2 = r - (r-l)/3;
		if (F(left, m1, right) < F(left, m2, right)) r = m2;
		else l = m1; 
	}
	if (l == r) return l;
	else if (l == r+1) {
		if (F(left, l, right) < F(left, l+1, right)) return l;
		else return l+1;
	}
	else {
		if (F(left, l, right) < F(left, l+1, right) && F(left, l+2, right))
			return l;
		else if (F(left, l+1, right) < F(left, l+2, right))
			return l+1;
		else return l+2;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sum[0] = 0;
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i-1] + a[i];
	long long ans = 1e17;
	for (int i = 2; i <= n-2; ++i) {
		int j = find(1, i-1);
		int k = find(i+1, n-1);
		long long maxt = max(sum[j], max(sum[i]-sum[j], max(sum[k]-sum[i], sum[n]-sum[k])));
		long long mint = min(sum[j], min(sum[i]-sum[j], min(sum[k]-sum[i], sum[n]-sum[k])));
		ans = min(ans, maxt-mint);
	}
	cout << ans << endl;
	return 0;
}