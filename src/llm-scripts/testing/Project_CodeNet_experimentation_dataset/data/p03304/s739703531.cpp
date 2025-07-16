#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 nn, mm, dd;
	long double ans = 0.0;
	cin >> nn >> mm >> dd;
	if(dd == 0)
	{
		ans += (long double)(mm - 1) / (long double)nn;
	}
	else
	{
		ans += (long double)(mm - 1) * 2.0 * (long double)(nn - dd) / (long double)(nn * nn);
	}
    cout << fixed << setprecision(20);
	cout << ans << endl;
	return 0;
}
