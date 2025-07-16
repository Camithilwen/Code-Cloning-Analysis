#include <iostream>
using namespace std;
int N, Q, tp, a, b, c, d[109][109];
int main() {
	while (cin >> N >> Q, N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) d[i][j] = 0;
				else d[i][j] = 999999999;
			}
		}
		while (Q--) {
			cin >> tp;
			if (tp == 1) {
				cin >> a >> b >> c; a--, b--;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						int dist2 = d[i][a] + c + d[b][j];
						if (d[i][j] > dist2) d[i][j] = dist2;
					}
				}
				swap(a, b);
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						int dist2 = d[i][a] + c + d[b][j];
						if (d[i][j] > dist2) d[i][j] = dist2;
					}
				}
			}
			else {
				cin >> a >> b; a--, b--;
				cout << (d[a][b] != 999999999 ? d[a][b] : -1) << endl;
			}
		}
	}
	return 0;
}