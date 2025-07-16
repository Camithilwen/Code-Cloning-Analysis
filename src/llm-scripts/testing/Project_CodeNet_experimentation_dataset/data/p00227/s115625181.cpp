#include <iostream>
#include <algorithm>
using namespace std;

const int N_MAX = 1000;

int n, m;
int p[N_MAX];

int main () {
	while (cin >> n >> m, n || m) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			sum += p[i];
		}
		sort(p, p + n, greater<int>());
		for (int i = m - 1; i < n; i += m) {
			sum -= p[i];
		}
		cout << sum << endl;
	}
	return 0;
}