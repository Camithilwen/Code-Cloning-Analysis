#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop//
//gcdlcm, isPrime, eratos, divisor, modinv, bitSearch, bitList, dfs, bfs//
//dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = INF;
vl flag, color, D; vll path;
//***********//
int main() {
	cin >> H >> W >> K;
	if (W == 1) cout << 1;
	else {
		vll sub_dp(W + 1, vl(2, 0));
		sub_dp[0][1] = 1;
		for (i = 0; i < W; i++) {
			sub_dp[i + 1][0] = sub_dp[i][0] + sub_dp[i][1];
			sub_dp[i + 1][1] = sub_dp[i][0];
		}
		vl sub(W + 1);
		for (i = 0; i < W + 1; i++) {
			sub[i] = (sub_dp[i][0] + sub_dp[i][1]) % MOD;
			//cout << sub[i] << endl;
		}
		vll dp(H + 1, vl(W, 0));
		dp[0][0] = 1;
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				if (j == 0) {
					dp[i + 1][j] = (dp[i][j + 1] * sub[W - 2] + dp[i][j] * sub[W - 1]) % MOD;
				}
				else if (j == W - 1) {
					dp[i + 1][j] = (dp[i][j - 1] * sub[W - 2] + dp[i][j] * sub[W - 1]) % MOD;
				}
				else {
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 1] * sub[j - 1] * sub[W - j - 1]) % MOD;
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * sub[j] * sub[W - j - 1]) % MOD;
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j + 1] * sub[j] * sub[W - j - 2]) % MOD;
				}
			}
		}
		cout << dp[H][K - 1];
	}
}