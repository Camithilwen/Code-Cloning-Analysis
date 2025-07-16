#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	vector<int>t(N);
	for (int i = 0;i<N;++i) {
		cin >> t[i];
	}
	int ans = 0;
	for (int i = 0;i<N-1;++i) {
		ans += min(T, t[i + 1] - t[i]);
	}
	ans += T;
	cout << ans << endl;
	return 0;
}