#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {

	int n, l; cin >> n >> l;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += l + i;
	}
	int ans;
	int x = 100000000;
	for (int i = 0; i < n; i++) {
		int tmp = l + i;
		if (chmin(x, abs(tmp))) {
			ans = sum - tmp;
		}
	}
	cout << ans << endl;
	return 0;
}