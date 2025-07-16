#include "bits/stdc++.h"

#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define all(co) co.begin(), co.end()
using namespace std;
//using P = pair<int, int>;

int main() {
	int n;
	while (cin >> n && n) {
		int k; cin >> k;
		vector<string> vec(n);
		rep(i, n) cin >> vec[i];

		set<string> sets;
		vector<bool> used(n);
		function<void(string, int)> dfs = [&](string str, int count) {
			if (count == k) {
				sets.insert(str);
				return;
			}
			rep(i, n) if (!used[i]) {
				used[i] = true;
				dfs(str + vec[i], count + 1);
				used[i] = false;
			}
		};
		dfs("", 0);
		cout << sets.size() << endl;
	}
	return 0;
}