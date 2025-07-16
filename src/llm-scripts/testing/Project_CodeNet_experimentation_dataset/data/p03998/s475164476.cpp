#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;

int main() {
	vector<vector<string>> data(3);
	string stra,strb,strc;
	string next = "a";
	cin >> stra;

	cin >> strb;

	cin >> strc;
	int a = 0, b = 0, c = 0;
	while (true) {
		if (next == "a") {
			if (a < stra.size()) {
				next = stra[a];
				a++;
			}
			else {
				cout << "A" << endl;
				break;
			}
		}
		else if (next == "b") {
			if (b < strb.size()) {
				next = strb[b];
				b++;
			}
			else {
				cout << "B" << endl;
				break;
			}

		}
		else {
			if (c< strc.size()) {
				next = strc[c];
				c++;
			}
			else {
				cout << "C" << endl;
				break;
			}

		}
	}

	return 0;

}