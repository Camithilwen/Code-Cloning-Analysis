#include <iostream>

using namespace std;

int main() {
	int n, m;
	int a[1010][2] = {0};
	int b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
	}
	for (int i = 0; i < m; i++) {
		cin >> b;
		for (int j = 0; j < n; j++) {
			if (a[j][0] <= b) {
				a[j][1]++;
				break;
			}
		}
	}
	int max[2] = {0};
	for (int i = 0; i < n; i++) {
		if (max[1] < a[i][1]) {
			max[1] = a[i][1];
			max[0] = i+1;
		}
	}
	cout << max[0] << endl;
	return 0;
}