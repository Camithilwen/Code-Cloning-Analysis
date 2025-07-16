#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_postal_code(void) {
	int a, b;
	string s;
	string msg = "Yes";
	cin >> a >> b >> s;
	if (s.size() != a + b + 1) msg = "No";
	else if (s[a] != '-') msg = "No";
	else {
		for (int i = 0; i < a + b + 1; i++) {
			if (i == a) continue;

			if (s[i] == '-') {
				msg = "No";
				break;
			}
		}
	}
	cout << msg << endl;
}

int main()
{
	b_postal_code();
    return 0;
}