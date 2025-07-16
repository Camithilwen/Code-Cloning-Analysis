#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int n;
long long a[N], sum[N];
int L[N], R[N];

inline long long calc(int st, int en, int p, int q) {
	long long s = sum[en] - sum[st - 1];
	long long s1 = sum[q] - sum[p - 1];
	long long s2 = s - s1;
	return abs(s1 - s2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	L[2] = 1;
	for (int i = 3; i <= n; i++) {
		L[i] = L[i - 1];
		while (L[i] + 1 < i && calc(1, i, 1, L[i]) > calc(1, i, 1, L[i]+1)) L[i]++;
	}
	R[n - 1] = n;
	for (int i = n - 2; i >= 1; i--) {
		R[i] = R[i + 1];
		while (R[i] - 1 > i && calc(i, n, R[i], n) > calc(i, n, R[i] - 1, n)) R[i]--;
	}
	long long ans = LLONG_MAX;
	for (int i = 2; i <= n - 1; i++) {
		vector<long long> v;
		v.push_back(sum[L[i]]);
		v.push_back(sum[i] - sum[L[i]]);
		v.push_back(sum[R[i + 1] - 1] - sum[i]);
		v.push_back(sum[n] - sum[R[i + 1] - 1]);
		sort(v.begin(), v.end());
		ans = min(ans, v[3] - v[0]);
	}
	cout << ans << endl;
	return 0;
}

