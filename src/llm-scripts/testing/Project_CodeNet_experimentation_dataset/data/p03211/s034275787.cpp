#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
#define MAX_N 100000
int main() {
	string s; cin >> s;
	int ans = INF;
	for (int i = 0; i < s.length() - 2; i++) {
		int tmp = (s[i] - '0') * 100;
		tmp += (s[i+1] - '0') * 10;
		tmp += (s[i+2] - '0');
		ans = min(ans, max(tmp-753, 753-tmp));
	}
	cout << ans << endl;
}