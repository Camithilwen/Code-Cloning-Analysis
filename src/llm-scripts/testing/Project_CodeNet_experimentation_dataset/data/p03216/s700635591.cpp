#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q; string S;
	cin >> N >> S >> Q;
	vector<int> dsum(N + 1), msum(N + 1);
	for (int i = 0; i < N; ++i) {
		dsum[i + 1] = dsum[i] + (S[i] == 'D' ? 1 : 0);
		msum[i + 1] = msum[i] + (S[i] == 'M' ? 1 : 0);
	}
	for (int i = 0; i < Q; ++i) {
		int K;
		cin >> K;
		long long cur = 0, ans = 0;
		for (int i = 0; i < N; ++i) {
			if (S[i] == 'C') {
				ans += cur;
			}
			if (S[i] == 'M') {
				cur += dsum[i] - dsum[max(i - K + 1, 0)];
			}
			if (i >= K - 1 && S[i - K + 1] == 'D') {
				cur -= msum[i + 1] - msum[i - K + 2];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}