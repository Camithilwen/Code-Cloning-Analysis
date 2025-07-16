#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define EPS 1e-10
using namespace std;
typedef long long llong;
int main() {
	int n;
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			int m, e, j;
			cin >> m >> e >> j;

			if (m == 100 || e == 100 || j == 100 || (m + e) / 2 >= 90 || (m + e + j) / 3 >= 80)cout << 'A' << endl;
			else if ((m + e + j) / 3 >= 70 || ((m + e + j) / 3 >= 50) && ((m >= 80) || (e >= 80)))cout << 'B' << endl;
			else cout << 'C' << endl;
		}
	}
	return 0;
}