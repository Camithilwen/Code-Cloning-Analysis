#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int len = s.size();
	int cnts = 0, cntst = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'S')
			cnts++;
		else if (s[i] == 'T' && cnts != 0) {
			cnts--;
			cntst += 2;
		}
	}
	cout << len - cntst << endl;
	return 0;
}