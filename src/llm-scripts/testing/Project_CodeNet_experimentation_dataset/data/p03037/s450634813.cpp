#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> L(M), R(M);
	for(int i = 0; i < M; ++i) {
		cin >> L[i] >> R[i];
	}
	vector<int> p(N + 1);
	for(int i = 0; i < M; ++i) {
		++p[L[i] - 1];
		--p[R[i]];
	}
	int sum = 0, ans = 0;
	for(int i = 0; i < N; ++i) {
		sum += p[i];
		if(sum == M) ++ans;
	}
	cout << ans << endl;
	return 0;
}