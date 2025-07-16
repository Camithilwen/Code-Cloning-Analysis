#include <iostream>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		int i, a[10001] = { 0 }, b[10001] = { 0 };
		bool list[2][1001] = { false };
		if (n == 0 && m == 0) goto END;
		for (i = 0; i < m; i++) {
			cin >> a[i] >> b[i];
			if (a[i] == 1) {
				list[0][b[i]] = true;
				list[1][b[i]] = true;
			}
			if (b[i] == 1) {
				list[0][a[i]] = true;
				list[1][a[i]] = true;
			}
		}
		for (i = 0; i < m; i++) {
			if (list[0][a[i]] == true) {
				list[1][b[i]] = true;
			}
			if (list[0][b[i]] == true) {
				list[1][a[i]] = true;
			}
		}
		int ans = 0;
		for (i = 2; i <= n; i++) {
			if (list[1][i]) ans++;
		}
		cout << ans << endl;
	}
END:;
	return 0;
}