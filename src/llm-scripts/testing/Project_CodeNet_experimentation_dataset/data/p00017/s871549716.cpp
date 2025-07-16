#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main() {
	string t;
	while(getline(cin,t)) {
		for(int i = 0; i < 26; i++) {
			for(int j = 0; j < t.size(); j++) {
				if(t[j] == ' ' || t[j] == '.') continue;
				t[j] += 1;
				if(t[j] > 'z') t[j] -= 26;
			}
			if(t.find("the") != string::npos || t.find("that") != string::npos || t.find("this") != string::npos) {
				cout << t << endl;
				break;
			}
		}
	}
	return 0;
}