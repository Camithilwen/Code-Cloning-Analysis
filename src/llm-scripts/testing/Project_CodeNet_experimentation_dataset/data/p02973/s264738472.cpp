#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		A[i] *= -1;
	}
	vector<int> seq(N, 1 << 30);
	for (int i = 0; i < N; ++i) {
		*lower_bound(seq.begin(), seq.end(), A[i] + 1) = A[i];
	}
	cout << lower_bound(seq.begin(), seq.end(), 1 << 30) - seq.begin() << endl;
	return 0;
}