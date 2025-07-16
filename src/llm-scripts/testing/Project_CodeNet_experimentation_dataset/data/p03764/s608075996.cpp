#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N, M, bx, x, by, y, XCount = 0, YCount = 0;
	const long long MOD = 1e9 + 7;
	cin >> N >> M >> bx;
	for (int i = 1; i < N; i++) {
		cin >> x;
		XCount += i * (N - i) * (x - bx);
		XCount = XCount % MOD;
		bx = x;
	}
	cin >> by;
	for (int i = 1; i < M; i++) {
		cin >> y;
		YCount += i * (M - i) * (y - by);
		YCount = YCount % MOD;
		by = y;
	}
	cout << (XCount * YCount) % MOD;
}