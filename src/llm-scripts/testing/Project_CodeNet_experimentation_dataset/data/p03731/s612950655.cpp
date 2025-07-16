#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int main() {
	int N, T;
	cin >> N >> T;

	long long X = 0;
	long long preT = 0;
	cin >> preT;
	for (int i = 0; i < N - 1; ++i) {
		int t; cin >> t;
		if (preT + T < t) {
			X += T;
		}
		else {
			X += (t - preT);
		}

		preT = t;
	}

	cout << X + T << endl;

	return 0;
}