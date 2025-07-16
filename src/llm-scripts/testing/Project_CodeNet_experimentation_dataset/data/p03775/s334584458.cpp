#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t N;
	cin >> N;

	int64_t rt = sqrt(N);
	for (int64_t i = rt; i > 0; i--) {
		if (N % i == 0) {
			//cout << i << endl;
			int64_t n = N / i;

			int64_t cnt = 0;
			int64_t m = N / i;
			while (m) {
				cnt++;
				m /= 10;
			}

			cout << cnt << endl;
			return 0;
		}
	}
}