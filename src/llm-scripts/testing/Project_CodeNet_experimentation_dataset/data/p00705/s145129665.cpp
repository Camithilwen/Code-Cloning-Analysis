#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, q;
	while (cin >> n >> q, n, q) {
		int mem[110] = {};
		int maxv = -1;
		for (int i = 0; i < n; i++){
			int m; cin >> m;
			for (int j = 0; j < m; j++) {
				int d; cin >> d;
				mem[d]++;
				maxv = max(maxv, d);
			}
		}
		int ans = 0, num = -1;
		for (int i = 0; i <= maxv; i++) {
			if (ans == 0) {
				if (mem[i] >= q) { ans = i; num = mem[i]; }
			}
			else if (mem[i] > num) { ans = i; num = mem[i]; }
		}
		cout << ans << endl;
	}
}