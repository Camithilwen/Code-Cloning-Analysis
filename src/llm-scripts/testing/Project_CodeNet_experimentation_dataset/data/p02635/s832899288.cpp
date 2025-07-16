#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
string S;
int K, M;
int memo[400][400][400];
bool visited[400][400][400];
map<int,int> memo_g;
int g(int q) {
	if (memo_g.count(q)) return memo_g[q];
	int r = 0, qq = q;
	while (qq >= 0 && S[qq] == '1') { -- qq; ++ r; }
	return memo_g[q] = r;
}
int f(int p, int r, int s) {
	if (r > K) return 0;
	if (p == (int)S.length()) {
		return 1;
	}
	if (visited[p][r][s]) return memo[p][r][s];
	visited[p][r][s] = true;
	int q = M-p-s;
	int res = 0;
	if (q >= 0 && S[q] == '0') {
		res += f(p+1, r, s);
	} else {
		int x = g(q);
		int qq = q-x;
		if (qq >= 0 && S[qq] == '0') {
			res += f(p+1, r+x, s+x);
		}
	}
	if (q >= 0 && S[q] == '1') {
		res += f(p+1, r, s);
	} else if (s > 0) {
		res += f(p+1, r, s-1);
	}
	return memo[p][r][s] = res % mod;
}
int main() {
	cin >> S >> K;
	M = (int)S.length()-1;
	cout << f(0, 0, 0) << endl;
}
