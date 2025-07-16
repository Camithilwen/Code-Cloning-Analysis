#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;

int main() {
	string s; cin >> s;
	int n = s.size();

	int ans = 0;
	int st = 0;
	rep(i, 0, n) {
		if (s[i] == 'S') ++st;
		else {
			if (st == 0) ++ans;
			else --st;
		}
	}
	cout << ans + st << endl;
	return 0;
}