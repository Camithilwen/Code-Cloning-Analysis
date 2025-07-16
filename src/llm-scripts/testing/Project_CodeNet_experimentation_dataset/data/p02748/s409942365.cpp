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

#define MAXN (1 << 20)

int a[MAXN], b[MAXN], c[MAXN];

int main() {
	int na, nb, m;
	cin >> na >> nb >> m;
	for (int i = 1; i <= na; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= nb; i++) {
		cin >> b[i];
	}
	int ret = MAXN;
	for (int i = 1; i <= m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		int cur = a[x] + b[y] - c;
		ret = min(ret, cur);
	}
	sort(a + 1, a + na + 1);
	sort(b + 1, b + nb + 1);
	ret = min(ret, a[1] + b[1]);
	cout << ret << endl;
	return 0;
}
