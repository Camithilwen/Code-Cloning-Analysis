#include "bits/stdc++.h"
using namespace std;

// Bit Matrix
const int MAX_ROW = 110; // to be set appropriately
const int MAX_COL = 110000; // to be set appropriately
struct BitMatrix {
	int H, W;
	bitset<MAX_COL> val[MAX_ROW];
	BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
	inline bitset<MAX_COL>& operator [] (int i) { return val[i]; }
};

// 掃き出し法
void GaussJordan(BitMatrix &A, bool is_extended = false) {
	vector<bool> used(A.H, 0);
	for (int col = 0; col < A.W; ++col) {
		if (is_extended && col == A.W - 1) break;
		int pivot = -1;
		for (int row = 0; row < A.H; ++row) {
			if (used[row]) continue;
			if (A[row][col]) {
				pivot = row;
				break;
			}
		}
		if (pivot == -1) continue;
		for (int row = 0; row < A.H; ++row) {
			if (row != pivot && A[row][col]) A[row] ^= A[pivot];
		}
		used[pivot] = true;
	}
}

const int MD = 60;
int main() {
	int N; cin >> N;
	vector<long long> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];

	// 方程式を立てる
	long long res = 0;
	BitMatrix B(MD + 1, N + 1);
	vector<bool> cannot(MD + 1, false);
	for (long long d = MD; d >= 0; --d) {
		// d 桁目が 1 が何個か
		int num = 0;
		for (int i = 0; i < N; ++i) {
			if (A[i] & (1LL << d)) ++num;
		}
		if (num == 0) {
			cannot[d] = true;
			continue;
		}
		else if (1 == (num % 2)) {
			cannot[d] = true;
			res += (1LL << d);
			continue;
		}

		for (int i = 0; i < N; ++i) {
			if (A[i] & (1LL << d)) B[MD - d][i] = 1;
		}
		B[MD - d][N] = 1;
	}
	GaussJordan(B, true);

	// 集計
	for (int d = MD; d >= 0; --d) {
		if (cannot[d]) continue;

		// d 行目が (0 0 0 ... 0 | 1) だったらダメ
		bool ok = false;
		for (int i = 0; i < N; ++i) if (B[MD - d][i]) ok = true;
		if (!B[MD - d][N]) ok = true;

		// 結果に 2 × 2^d が寄与
		if (ok) res += (2LL << d);
	}
	cout << res << endl;
}