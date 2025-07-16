#include <iostream>
using namespace std;
int main() {
	int n, m, i, point[1000] = { 0 }, kyougi[1000] = { 0 }, ans = 0, tmp = 0, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> kyougi[i];
	}
	for (i = 0; i < m; i++) {
		int sinsa;
		cin >> sinsa;
		for (j = 0; j < n; j++) {
			if (kyougi[j] <= sinsa) {
				point[j]++;
				break;
			}
		}
	}
	for (i = 0; i < m; i++) {
		if (tmp < point[i]) {
			tmp = point[i];
			ans = i;
		}
	}
	cout << ans+1 << endl;
	return 0;
}