#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

int x[100001], y[100001];
ll sumx[100001], sumy[100001]; // sum[i] ; 1～iまでの和

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	sumx[0] = sumy[0] = 0LL;

	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		sumx[i] = sumx[i - 1] + x[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> y[i];
		sumy[i] = sumy[i - 1] + y[i];
	}

	ll L = 0LL;
	for (int i = 1; i <= m; i++) {
		L += sumy[m] - sumy[i] - (m - i)*ll(y[i]);
		L %= MOD;
	}

	ll K = 0LL;
	for (int i = 1; i <= n; i++) {
		K += sumx[n] - sumx[i] - (n - i)*ll(x[i]);
		K %= MOD;
	}

	cout << K * L % MOD << endl;

	return 0;
}