#include <bits/stdc++.h>
using namespace std;

bool isOK(vector<int> v) {
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			if (abs(v[j] - v[i]) == j - i) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int k;
	cin >> k;
	vector<int> x(k), y(k);
	for (int i = 0; i < k; i++) {
		cin >> x[i] >> y[i];
	}
	vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7 };
	do {
		bool OK = true;
		for (int i = 0; i < k; i++) {
			if (v[x[i]] != y[i]) {
				OK = false;
			}
		}
		if (OK && isOK(v)) {
			break;
		}
	} while (next_permutation(v.begin(), v.end()));
	vector<string> res(8, "........");
	for (int i = 0; i < 8; i++) {
		res[i][v[i]] = 'Q';
	}
	for (int i = 0; i < 8; i++) {
		cout << res[i] << endl;
	}
	return 0;
}