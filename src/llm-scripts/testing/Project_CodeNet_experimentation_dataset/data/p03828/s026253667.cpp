#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

#define MAX_T 1000+1
int T[MAX_T];

// 素因数分解O(√n)
map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i*i <= n; i++) {
		while (n % i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

int main() {
	int N; cin >> N;
	for (int i = 2; i <= N; i++) {
		map<int, int> ma = prime_factor(i);
		for (auto j = ma.begin(); j != ma.end(); j++) {
			T[j->first] += j->second;
		}
	}
	ll ans = 1;
	for (int i = 2; i < MAX_T; i++) {
		if (T[i] == 0) continue;
		ans = ans * (T[i] + 1) % MOD;
	}
	cout << ans << endl;
}