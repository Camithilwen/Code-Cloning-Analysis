#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

int f(int x) {
	if (x <= 3) {
		return (4 - x);
	}
	return 0;
}

int main() {
	int x, y;
	cin >> x >> y;
	if (x == 1 && y == 1) {
		cout << 1000000 << endl;
	} else {
		cout << 100000 * (f(x) + f(y)) << endl;
	}
	return 0;
}
