#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;

char encode(char c, int n) {
	char ret = c;
	for (int i = 0; i < n; i++) {

		if (ret == 'a') {
			ret = 'Z';
		}
		else if (ret == 'A') {
			ret = 'z';
		}
		else {
			ret -= 1;
		}
	}
	return ret;
}

int main(void) {
	int n;
	cin >> n;

	while (n != 0) {
		std::vector<int> k(n);
		std::string str;
		for (int i = 0; i < n; i++) {
			cin >> k[i];
		}
		
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			cout << encode(str[i], k[i%n]);
		}
		cout << endl;

		cin >> n;
	}

	return 0;
}