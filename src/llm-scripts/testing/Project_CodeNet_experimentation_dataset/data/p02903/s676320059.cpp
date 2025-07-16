
// A - 01 Matrix

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int grid[1000][1000];


int main() {
	int H, W, A, B;
	cin >> H >> W >> A >> B;

	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			if ((i < B && j < A) || (i >= B && j >= A)) {
				grid[i][j] = 0;
			} else {
				grid[i][j] = 1;
			}
		}
	}

	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}

	return 0;
}