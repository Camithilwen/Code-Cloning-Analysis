#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string str; 
	while (getline(cin, str)) {
		for (int i = 0; i < 26; i++) {
			for (auto &itr : str) if (isalpha(itr)) itr = (itr - 'a' + 1) % 26 + 'a';
			if (str.find("the") != -1) { cout << str << endl; break; }
			if (str.find("this") != -1) { cout << str << endl; break; }
			if (str.find("that") != -1) { cout << str << endl; break; }
		}
	}
	return 0;
}
