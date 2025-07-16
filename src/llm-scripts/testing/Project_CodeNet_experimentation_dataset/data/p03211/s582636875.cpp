#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int ans = 2147483647;
	for (int i = 0; i < s.size()-2; i++) {
		string tmp = s.substr(i, 3);
		ans = min(ans, abs(stoi(tmp) - 753));
	}
	cout << ans << endl;
	return 0;
}