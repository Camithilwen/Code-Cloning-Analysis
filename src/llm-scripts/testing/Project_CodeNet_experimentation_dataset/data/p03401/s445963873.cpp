#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N + 2);
	A[0] = 0;
	A[N + 1] = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		A[i + 1] = a;
	}
	int ans = 0;
	for (int i = 0; i < N + 1; ++i) {
		ans += abs(A[i + 1] - A[i]);
	}
	for (int i = 0; i < N; ++i) {
		cout << ans + abs(A[i + 2] - A[i]) - abs(A[i + 1] - A[i]) - abs(A[i + 2] - A[i + 1]) << endl;
	}
	return 0;
}
