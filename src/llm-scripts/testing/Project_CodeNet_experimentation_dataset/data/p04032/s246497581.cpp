#include<iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0;i <= (signed)s.length() - 3;i++) {
		if (s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2]) {
			cout << i + 1 << " " << i + 3 << endl;
			return 0;
		}
	}
	if (s.length() >= 2) {
		if (s[s.length() - 1] == s[s.length() - 2]) {
			cout << s.length() - 1 << " " << s.length() << endl;
			return 0;
		}
	}
	cout << "-1 -1\n";
}