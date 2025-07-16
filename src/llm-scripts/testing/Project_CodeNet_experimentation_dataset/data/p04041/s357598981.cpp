#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MAXS = 1 << 16;

int main() {
	int N, X, Y, Z;
	cin >> N >> X >> Y >> Z;

	int xyz = (1 << (X + Y + Z - 1)) | (1 << (Y + Z - 1)) | (1 << (Z - 1));
	int mask = (1 << (X + Y + Z)) - 1;
	int mask2 = mask >> 1;

	int dp[2][MAXS];
	int idx = 0, _idx;
	dp[idx][0] = 1;
	for (int k = 0; k < N; ++k) {
		_idx = idx;
		idx ^= 1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		for (int i = 0; i <= mask2; ++i) {
			if (dp[_idx][i] > 0) {
				for (int j = 1; j <= 10; j++) {
					int _i = ((i << j) | (1 << (j-1)));
					if ((_i&xyz) != xyz) (dp[idx][_i&mask2] += dp[_idx][i]) %= MOD;
				}
			}
		}
	}
	long res = 1;
	for (int i = 0; i < N; ++i) (res *= 10) %= MOD;
	for (int i = 0; i <= mask2; ++i) (res -= dp[idx][i]) %= MOD;

	cout << (res + MOD) % MOD << endl;

	return 0;
}
