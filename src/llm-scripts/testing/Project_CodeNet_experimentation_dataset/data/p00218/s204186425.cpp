#include <iostream>
using namespace std;

#define full (m == 100 || e == 100 || j == 100)
#define avg(n) (m + e + j >= n)
#define me80 (m >= 80 || e >= 80)

int main() {
	int n, m, e, j;
	while (1) {
		cin >> n; if (n == 0)break;
		for (int i = 0; i < n; i++) {
			cin >> m >> e >> j;
			if (full || m + e >= 180 || avg(240)) cout << "A" << endl;
			else if (avg(210) || (avg(150) && me80)) cout << "B" << endl;
			else cout << "C" << endl;
		}
	}
	return 0;
}
