#include <cmath>
#include <iostream>
using namespace std;
int main() {
	int N, L;
	cin >> N >> L;
	int opt = (1 << 30), sum = 0;
	for (int i = 0; i < N; ++i) {
		int p = L + i;
		if (abs(opt) > abs(p)) {
			opt = p;
		}
		sum += p;
	}
	cout << sum - opt << endl;
	return 0;
}