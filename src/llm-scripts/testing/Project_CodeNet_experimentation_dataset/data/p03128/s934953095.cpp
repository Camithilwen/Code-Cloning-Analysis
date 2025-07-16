#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

int dat[10] = { 0,2,5,5,4,5,6,3,7,6 };

int N, M, A[1 << 18];
int dp[1 << 18];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i];

	for (int i = 0; i <= N; i++) dp[i] = -(1 << 30);
	dp[0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int k = 1; k <= M; k++) dp[i + dat[A[k]]] = max(dp[i + dat[A[k]]], dp[i] + 1);
	}

	int val = N; string S = "";
	while (val > 0) {
		int r = 0;
		for (int i = 1; i <= M; i++) {
			if (val >= dat[A[i]] && dp[val] - 1 == dp[val - dat[A[i]]]) r = max(r, A[i]);
		}
		val -= dat[r]; S += ('0' + r);
	}
	//reverse(S.begin(), S.end());
	cout << S << endl;
	return 0;
}