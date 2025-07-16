#include<bits/stdc++.h>
using namespace std;


int main() {
	int N, x;
	cin >> N >> x;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	vector<int> cpa = a;

	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			if (cpa[i] > x) ans += cpa[i] - x, cpa[i] = x;
		}
		else {
			if (cpa[i] + cpa[i-1] > x) ans += cpa[i] + cpa[i-1] - x, cpa[i] = x - cpa[i-1];
		}
	}

	cpa = a;
	long long ans2 = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (i == N - 1) {
			if (cpa[i] > x) ans2 += cpa[i] - x, cpa[i] = x;
		}
		else {
			if (cpa[i] + cpa[i+1] > x) ans2 += cpa[i] + cpa[i+1] - x, cpa[i] = x - cpa[i+1];
		}
	}



	cout << min(ans, ans2) << endl;
	return 0;
}