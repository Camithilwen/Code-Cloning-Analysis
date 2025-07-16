#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int i = 0; i < H; i++) cin >> S[i];
	vector<vector<int> > A(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '.') A[i][j] = 0;
			else A[i][j] = 1;
		}
	}
	vector<vector<int> > B(H, vector<int>(W - 1));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W - 1; j++) {
			B[i][j] = A[i][j] ^ A[i][j + 1];
		}
	}
	vector<vector<int> > C(H, vector<int>(W - 1));
	for (int i = 0; i < W - 1; i++) {
		C[H - 1][i] = 1;
		for (int j = H - 2; j >= 0; j--) {
			if (B[j + 1][i] == B[j][i]) C[j][i] = C[j + 1][i] + 1;
			else C[j][i] = 1;
		}
	}
	int ANS = 0;
	for (int i = 0; i < H; i++) {
		stack<pair<int, int> > ST;
		ST.push({ C[i][0], 0 });
		for (int j = 1; j < W - 1; j++) {
			int X = j;
			while (!ST.empty() && ST.top().first > C[i][j]) {
				ANS = max(ANS, ST.top().first * (j - ST.top().second + 1));
				X = ST.top().second;
				ST.pop();
			}
			ST.push({ C[i][j], X });
		}
		while (!ST.empty()) {
			ANS = max(ANS, ST.top().first * (W - ST.top().second));
			ST.pop();
		}
	}
	cout << max(ANS, max(H, W)) << endl;
}