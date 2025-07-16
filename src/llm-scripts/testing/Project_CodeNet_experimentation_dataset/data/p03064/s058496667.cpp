#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)

using namespace std;

uint64_t kRem = 998244353;


int64_t pow_rem(int64_t val, int64_t mul, int64_t rem)
{
	if (mul == 1) return val;

	int64_t ret = pow_rem(val, mul / 2, rem);
	ret *= ret;
	ret %= rem;

	if (mul & 1) {
		ret *= val;
		ret %= rem;
	}

	return ret;
}

int main()
{
	int n; cin >> n;
	vector<int> ns(n);
	int m = 0;
	for (auto& elem : ns) {
		cin >> elem;
		m += elem;
	}

	vector<vector<int64_t>> dp_r(n, vector<int64_t> (m + 1));

	dp_r[0][0] = 2;
	dp_r[0][ns[0]] = 1;

	FOR_LT(i, 0, n - 1) {
		FOR_LE(v, 0, m) {
			if (dp_r[i][v] != 0) {
				dp_r[i + 1][v] += dp_r[i][v] * 2;
				dp_r[i + 1][v + ns[i + 1]] += dp_r[i][v];
			}
		}

		FOR_LE(v, 0, m) {
			if (dp_r[i + 1][v] != 0) {
				dp_r[i + 1][v] %= kRem;
			}
		}
	}


	vector<vector<int64_t>> dp_rb(n, vector<int64_t>(m + 1));
	dp_rb[0][0] = 1;
	dp_rb[0][ns[0]] = 1;

	FOR_LT(i, 0, n - 1) {
		FOR_LE(v, 0, m) {
			if (dp_rb[i][v] != 0) {
				dp_rb[i + 1][v] += dp_rb[i][v];
				dp_rb[i + 1][v + ns[i + 1]] += dp_rb[i][v];
			}
		}

		FOR_LE(v, 0, m) {
			if (dp_rb[i + 1][v] != 0) {
				dp_rb[i + 1][v] %= kRem;
			}
		}
	}

	int64_t ng_cases = 0;
	FOR_LE(v, ((m + 1) / 2), m) {
		ng_cases += dp_r[n - 1][v];
		ng_cases %= kRem;
	}
	if ((m & 1) == 0) {
		ng_cases -= dp_rb[n - 1][m / 2];
		if (ng_cases < 0) ng_cases += kRem;
	}
	ng_cases *= 3;
	ng_cases %= kRem;

	int64_t all_cases = 0;
	all_cases = pow_rem(3, n, kRem);

	int64_t ans = (all_cases - ng_cases);
	if (ans < 0) ans += kRem;
 
	cout << ans << endl;
}