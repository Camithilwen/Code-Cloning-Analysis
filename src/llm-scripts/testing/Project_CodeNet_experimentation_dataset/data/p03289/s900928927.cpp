#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string S;
	cin >> S;

	string ans = "WA";

	vector<int> up;
	for (int i = 0; i < S.size(); ++i) {
		if ('a' > S[i] || S[i] > 'z') {
			up.push_back(i);
		}
	}

	if (up.size() == 2 && up[0] == 0 && S[up[0]] == 'A') {
		if (2 <= up[1] && up[1] <= S.size() - 2 && S[up[1]] == 'C') {
			ans = "AC";
		}
	}

	cout << ans << endl;
	return 0;
}
