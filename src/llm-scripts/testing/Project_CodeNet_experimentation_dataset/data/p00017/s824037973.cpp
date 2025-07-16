#include <iostream>
#include <string>
using namespace std;

int main() {
	string cipher;

	while (getline(cin, cipher)) {
		for (int i = 0; i < 26;i++) {
			for (unsigned int n = 0;n < cipher.length();n++) {
				if (cipher.at(n) == 'z') {
					cipher.at(n) = 'a';
				}
				else if (cipher.at(n) >= 'a'&&cipher.at(n) <= 'y') {
					cipher.at(n)++;
				}
			}

			if (cipher.find("the") != string::npos ||
				cipher.find("this") != string::npos ||
				cipher.find("that") != string::npos) {
				cout << cipher << endl;
			}
		}
	}
	
	
	return 0;
}