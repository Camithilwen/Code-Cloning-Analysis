#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <vector>;
using namespace std;

int main() {
	
	int d, s, t;
	cin >> d >> s >> t;

	int m = d / s;
	if (d % s != 0) m++;

	if (m <= t) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}


	return 0;
}