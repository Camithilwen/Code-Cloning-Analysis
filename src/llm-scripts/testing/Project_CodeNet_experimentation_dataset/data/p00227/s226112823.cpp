#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

typedef unsigned long long ull;

using namespace std;

int main() {
	int n, m;
	int ps[1000];
	for (;;) {
		cin >> n >> m;
		if (!(n | m))
			break;
		int ans = 0;
		REP(i,n) {
			cin >> ps[i];
			ans += ps[i];
		}
		if (n < m) {
			cout << ans << endl;
			continue;
		}
		sort(ps, ps + n, greater<int>());
		for (int i = m - 1; i < n; i += m) {
			ans -= ps[i];
		}
		cout << ans << endl;
	}
	return 0;
}