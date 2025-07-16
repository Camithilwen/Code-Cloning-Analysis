#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int p[11];
int c[11];

int main() {
	int d, g;
	cin >> d >> g;
	for (int i = 0; i < d; i++)
		cin >> p[i] >> c[i];
	int ans = 1e9;
	for (int i = 0; i < (1 << d); i++) {
		int tmp = 0;
		long sum = 0;
		for (int j = 0; j < d; j++) {
			if (i & (1 << j)) {
				tmp += p[j];
				sum += 100 * (j + 1) * p[j] + c[j];
			}
		}
		for (int j = d - 1; j >= 0 && sum < g; j--) {
			if (!(i & (1 << j))) {
				for (int l = 1; l <= p[j] && sum < g; l++) {
					tmp++;
					sum += 100 * (j + 1);
				}
			}
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}