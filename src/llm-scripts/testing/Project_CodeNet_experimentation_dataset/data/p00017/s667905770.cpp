#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long llong;
int main() {
	int p, q, r;
	string x = "this the that";
	//cout << x.find("the") << endl << x.find("that") << endl << x.find("this") << endl;
	string a = "abcde";
	//cout << (int)a.find("the") << endl << (int)a.find("that") << endl << (int)a.find("this") << endl;
	string s;
	while (getline(cin, s)) {
		//cout << (int)s.find("the") << endl << (int)s.find("that") << endl << (int)s.find("this") << endl;
		for (int j = 0;; j++) {
			p = (int)s.find("the");
			q = (int)s.find("that");
			r = (int)s.find("this");
			//cout << p << q << r << endl;
			if (p >= 0 || q >= 0 || r >= 0) {
				cout << s << endl;
				break;
			}
			for (int i = 0; i < s.size(); i++) {
				if (isalpha(s[i])) {
					if (s[i] == 'z')s[i] = 'a';
					else s[i]++;

				}
			}
		}
	}
	return 0;
}