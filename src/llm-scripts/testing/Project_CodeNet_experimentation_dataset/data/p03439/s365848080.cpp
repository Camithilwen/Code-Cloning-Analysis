#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << 0 << endl;
	string s;
	cin >> s;

	int a;
	if (s == "Male") {
		a = 1;
	} else if (s == "Female") {
		a = 0;
	}

	int l = 0, r = n;
	while (s != "Vacant") {
		int c = (l + r) / 2;
		cout << c << endl;
		cin >> s;

		if (s == "Male") {
			if (a) {
				if (c & 1 == 1) {
					r = c;
				} else {
					l = c;
				}
			} else {
				if (c & 1 == 1) {
					l = c;
				} else {
					r = c;
				}
			}
		} else if (s == "Female") {
			if (a) {
				if (c & 1 == 1) {
					l = c;
				} else {
					r = c;
				}
			} else {
				if (c & 1 == 1) {
					r = c;
				} else {
					l = c;
				}
			}
		}
	}

	return 0;
}