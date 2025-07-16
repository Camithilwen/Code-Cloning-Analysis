#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a != b && b != c && c != a) {
		cout << "No" << endl;
	}
	else if (a == b && b == c) {
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;

	return 0;
}