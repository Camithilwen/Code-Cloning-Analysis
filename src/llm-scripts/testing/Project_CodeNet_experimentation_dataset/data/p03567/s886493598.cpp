#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv) {
	string s;
	cin >> s;
	bool ok = false;
	for (int i = 0; i < s.length() - 1; ++i) {
		ok |= s[i] == 'A' && s[i + 1] == 'C';
	}
	cout << (ok ? "Yes" : "No") << endl;
}
