#include <iostream>
#include <cmath>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, A[509][509];
vector<tuple<int, int, int, int>> L;

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> A[i][j];
	}
	for (int i = 1; i <= H; i++) {
		for (int j = W - 1; j >= 1; j--) {
			if (A[i][j + 1] % 2 == 0) continue;
			L.push_back(make_tuple(i, j + 1, i, j));
			A[i][j + 1]--;
			A[i][j]++;
		}
	}
	for (int i = H - 1; i >= 1; i--) {
		if (A[i + 1][1] % 2 == 0) continue;
		L.push_back(make_tuple(i + 1, 1, i, 1));
		A[i + 1][1]--;
		A[i][1]++;
	}

	cout << L.size() << endl;
	for (int i = 0; i < L.size(); i++) cout << get<0>(L[i]) << " " << get<1>(L[i]) << " " << get<2>(L[i]) << " " << get<3>(L[i]) << endl;
	return 0;
}