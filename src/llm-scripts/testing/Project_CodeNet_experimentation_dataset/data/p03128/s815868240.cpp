
// D - Match Matching

// DPによる解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

string dp[10030]; // dp[i]: i本のマッチで作れる最大の数
int m[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string max_v(string v1, string v2) {
	if (v1.size() > v2.size()) return v1;
	if (v1.size() < v2.size()) return v2;

	if (v1 > v2) return v1;
	else return v2;
}


int main() {
	int N, M;
	cin >> N >> M;

	vector<int> A;

	for (int i=0; i<M; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	for (int i=1; i<=N; i++) {
		dp[i] = "#";
	}

	for (int i=0; i<=N; i++) {
		for (int a : A) {
			if (dp[i] == "#") continue;

			dp[i+m[a]] = max_v(dp[i+m[a]], dp[i] + (char)('0' + a));
		}
	}

	cout << dp[N] << endl;

	/*
	// **** debug ****
	for (int i=0; i<=N; i++) {
		cout << dp[i] << endl;
	}
	*/

	return 0;
}