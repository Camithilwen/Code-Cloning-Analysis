#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
map<int, int> mp;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	rep(i, n)	cin >> x[i];
	int lower, upper;
	lower = 0;
	upper = k - 1;
	int ans = iINF, tmpans = iINF;
	while (upper < n) {
		tmpans = iINF;
		if (x[lower] <= 0 && x[upper] <= 0)			tmpans = abs(x[lower]);
		else if (0 <= x[lower] && 0 <= x[upper])	tmpans = x[upper];
		else {
			tmpans = 2 * min(abs(x[lower]), abs(x[upper]));
			tmpans += max(abs(x[lower]), abs(x[upper]));
		}
		if (tmpans < ans)	ans = tmpans;
		lower++;
		upper++;
	}
	cout << ans << endl;
	return 0;
}
