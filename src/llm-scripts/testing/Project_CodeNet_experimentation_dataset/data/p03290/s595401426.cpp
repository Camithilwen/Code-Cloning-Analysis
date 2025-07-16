#include <bits/stdc++.h>

using namespace std;

int main()
{
	int D, G;
	cin >> D >> G;
	vector < int >p(D), c(D);
	for (int i = 0; i < D; i++) {
		cin >> p[i] >> c[i];
	}

	int ans = INT_MAX;
	for (int bits = 0; bits < (1 << D); bits++) {
		int score = 0;
		int num = 0;
		int resultMax = -1;
		for (int i = 0; i < D; i++) {
			if (bits >> i & 1) {
				score += 100 * (1 + i) * p[i] + c[i];
				num += p[i];
			} else {
				resultMax = i;
			}
		}

		if (score < G) {
			int s1 = 100 * (resultMax + 1);
			int need = (G - score + s1 - 1) / s1;
			if (need >= p[resultMax]) {
				continue;
			}
			num += need;
		}
		ans = min(ans, num);
	}

	cout << ans << endl;

	return 0;
}
