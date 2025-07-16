#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	int r;
	cin >> r;

	string s;
	if (r < 1200) {
		s = "ABC";
	} else if (r < 2800) {
		s = "ARC";
	} else {
		s = "AGC";
	}

	cout << s << endl;
	return 0;
}
