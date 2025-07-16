#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 1 << 25;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m, query;
	while (cin >> n >> m , n) {
		int cost[101][101], time[101][101];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cost[i][j] = (i == j) ? 0 : INF;
				time[i][j] = (i == j) ? 0 : INF;
			}
		}

		while (n--) {
			int a, b, c, t;
			cin >> a >> b >> c >> t;
			cost[a - 1][b - 1] = cost[b - 1][a - 1] = c;
			time[a - 1][b - 1] = time[b - 1][a - 1] = t;
		}

		for (int k = 0; k < m; k++) {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
					time[i][j] = min(time[i][j], time[i][k] + time[k][j]);
				}
			}
		}

		cin >> query;
		while (query--) {
			int p, q, r;
			cin >> p >> q >> r;
			if (r == 0) {
				cout << cost[p - 1][q - 1] << endl;
			}
			else {
				cout << time[p - 1][q - 1] << endl;
			}
		}
	}
}