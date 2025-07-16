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
#include <functional>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int64_t kRem = 1000000007;

int64_t factorial_rem(int n, int64_t rem)
{
	if (n == 0) return 0;

	int64_t ans = 1;
	FOR_LE(i, 1, n) {
		ans *= i;
		ans %= rem;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;

	int64_t c = 0;
	int64_t ans = 1;
	FOR_LT(i, 0, 2 * n) {
		int cc = c;
		if (s[i] == 'B') {
			cc++;
		}

		if (cc & 1) c++;
		else {
			ans *= c;
			ans %= kRem;
			c--;
		}
	}
	if (c != 0) {
		cout << 0 << endl;
		return 0;
	}

	ans *= factorial_rem(n, kRem);
	ans %= kRem;

	cout << ans << endl;

	return 0;
}