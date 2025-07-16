#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	string ans = "";
	for (int i = 0; i < n; i++) {
		ans += 'x';
	}
	for (int i = 0; i < m; i++) {
		int s; char c; cin >> s >> c;
		s--;
		if (ans[s] != 'x') {
			if (ans[s] == c) {}
			else { // ans[s] != c
				cout << -1 << endl;
				return 0;
			}
		}
		else { // ans[s] == 'x'
			ans[s] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0 && ans[i] == 'x') ans[i] = '0';
		else if (i == 0 && ans[i] == 'x' && ans.size() != 1) ans[i] = '1';
		else if (i == 0 && ans[i] == 'x' && ans.size() == 1) ans[i] = '0';
	}
	if (ans[0] == '0' && 2 <= ans.size()) ans = "-1";
	cout << ans << endl;
    return 0;
}