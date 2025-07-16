// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int aa[N], ii[N], ft[N];

void update(int i, int n, int x) {
	while (i < n) {
		ft[i] = max(ft[i], x);
		i |= i + 1;
	}
}

int query(int i) {
	int x = 0;
	while (i >= 0) {
		x = max(x, ft[i]);
		i &= i + 1, i--;
	}
	return x;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> aa[i];
		ii[i] = i;
	}
	sort(ii, ii + n, [] (int i, int j) { return aa[i] > aa[j] || aa[i] == aa[j] && i < j; });
	int ans = 0;
	for (int h = 0; h < n; h++) {
		int i = ii[h];
		int k = query(i) + 1;
		ans = max(ans, k);
		update(i, n, k);
	}
	cout << ans << '\n';
	return 0;
}
