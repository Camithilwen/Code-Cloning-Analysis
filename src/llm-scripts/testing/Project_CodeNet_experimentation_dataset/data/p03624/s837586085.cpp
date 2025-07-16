#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	vector<bool> v(26);
	for (int i = 0; i < S.size(); i++) {
		char ch = S.at(i);
		int n = (int)ch - 97;
		v.at(n) = 1;
	}

	string ans = "None";
	for (int i = 0; i < 26; i++) {
		if (v.at(i) == 0) {
			ans = (char)i + 97;
			break;
		}
	}

	cout << ans << endl;
}