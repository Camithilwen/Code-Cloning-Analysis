#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	vector<int> A(N), v(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	vector<int> C;
	for (int i = N - 1; i >= 0; i--) {
		int n = i + 1;
		int c = 0;
		for (int j = i; j < N; j += n) {
			if (v[j]) c++;
		}
		c %= 2;
		//cout << c << endl;
		v[i] = A[i] - c;
		if (v[i]) C.push_back(i + 1);
	}
	sort(C.begin(), C.end());

	cout << C.size() << endl;
	if (C.size()) {
		for (int i = 0; i < C.size(); i++) {
			if (i) cout << ' ';
			cout << C[i];
		}
		cout << endl;
	}
}