#include <string>
#include <iostream>
using namespace std;

int n;
string s;

bool match(int index, string pattern) {
	if (index + pattern.size() > s.size()) return false;
	for (int i = 0; i < pattern.size(); i++) {
		if (s[index + i] != pattern[i])
			return false;
	}
	return true;
}

int change() {
	string after = "Hoshina", before = "Hoshino";
	for (int i = 0; i < s.size(); i++) {
		if (match(i, before)) {
			for (int j = 0; j < before.size(); j++) {
				s[i + j] = after[j];
			}
		}
	}
	return 0;
}

int main(){
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		change();
		cout << s << endl;
	}

	return 0;
}