#include<bits/stdc++.h>
#define mod (long)(1e9 + 7)
using namespace std;

long dp[10000][2][100];

long solve(int curr, int tight, int sum, string &s, int d) {
	if(curr == s.size()) {
		return (sum == 0);
	}
	if(dp[curr][tight][sum] != -1) return dp[curr][tight][sum];
	if(tight) {
		long res = 0;
		for(int i = 0; i <= (s[curr] - '0'); ++i) {
			res = (res + solve(curr + 1, tight & (i == (s[curr]-'0')), (sum + i) % d, s, d)) % mod;
		}
		return dp[curr][tight][sum] = res;
	}
	long res = 0;
	for(int i = 0; i < 10; ++i) {
		res = (res + solve(curr + 1, tight, (sum + i) % d, s, d)) % mod;
	}
	return dp[curr][tight][sum] = res;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	string k;
	int d;
	cin >> k >> d;
	memset(dp, -1, sizeof dp);
	cout << (solve(0, 1, 0, k, d) - 1 + mod) % mod;

	return 0;
}