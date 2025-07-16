#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> v(n, 0);
	bool fail = false;
	int tmp;
	cin >> tmp;
	if (tmp != 0) fail = true;
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		if (tmp == 0) fail = true;
		v[tmp]++;
	}
	if (fail) cout << 0 << endl;
	else {
		long long ans = 1;
		for (int i = 1; i < n-1; i++) {
			for (int j = 0; j < v[i+1]; j++) {
				ans *= v[i];
				ans %= 998244353;
			}
		}
		cout << ans << endl;
	}
}

