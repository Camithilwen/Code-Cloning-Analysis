#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	string abc = "abcdefghijklmnopqrstuvwxyz";
	string abcc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string aa = abcc + abc + abcc + abc;
	int sz = aa.size();
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vector<int> k(n);
		for (int i = 0; i < n; i++) {
			cin >> k[i];
		}
		string s;
		cin >> s;
		int c = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = sz - 1; j >= 0; j--) {
				if (aa[j] == s[i]) {
					cout << aa[j - k[c]];
					c++;
					c %= n;
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}