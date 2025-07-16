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

struct dish {
	ll x, y;

	dish(ll tx = 0, ll ty = 0) {
		x = tx;
		y = ty;
	}

	void read() {
		cin >> x >> y;
	}

	bool operator<(const dish & d) const {
		return (x + y > d.x + d.y);
	}
};

#define MAXN (1 << 17)

dish a[MAXN];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i].read();
	}
	sort(a, a + n);
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			ret -= a[i].y;
		} else {
			ret += a[i].x;
		}
	}
	cout << ret << endl;

	return 0;
}
