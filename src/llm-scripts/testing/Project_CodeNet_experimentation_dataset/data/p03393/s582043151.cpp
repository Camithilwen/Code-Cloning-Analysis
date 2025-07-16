#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	string s,ans;
	cin >> s;
	ans = s;
	map<char, int>m;
	rep(i, 26)m[char('a' + i)]++;
	if(s.size() == 26){
		char c = ' ';
		for (int i = 25; i > 0;i--) {
			if (s[i-1] < s[i]) {
				ans = s.substr(0, i - 1);
				c = s[i -1];
				break;
			}
		}
		for (auto ss : ans)m[ss]--;
		for (auto mm : m) {
			if (mm.second == 1 && c < mm.first) {
				ans += mm.first;
				break;
			}
		}

	}
	else {
		for (auto ss : s)m[ss]--;
		for (auto mm : m) {
			if (mm.second == 1) {
				ans = s + mm.first;
				break;
			}
		}
	}
	if (s != ans) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}

