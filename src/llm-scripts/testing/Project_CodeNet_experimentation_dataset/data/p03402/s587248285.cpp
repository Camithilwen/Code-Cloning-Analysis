#include<iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b; a--; b--;
	cout << "100 100" << endl;

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 100; j++) {
			if (a > 0 && i % 2 == 0 && j % 2 == 1) { cout << '.'; a--; }
			else cout << '#';
		}
		cout << endl;
	}

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 100; j++) {
			if (b > 0 && i % 2 == 1 && j % 2 == 1) { cout << '#'; b--; }
			else cout << '.';
		}
		cout << endl;
	}

	return 0;
}