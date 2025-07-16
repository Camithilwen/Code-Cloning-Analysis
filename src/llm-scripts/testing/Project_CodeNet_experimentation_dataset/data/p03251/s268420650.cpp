#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ldouble = long double;

const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s) cout << fixed << setprecision(10) << s << endl;


int main()
{
	ll m, n, x, y;
	cin >> m >> n >> x >> y;

	vector<ll> a(m);
	ll a0 = -101;
	for (ll i = 0; i < m; i++)
	{
		cin >> a[i];

		a0 = max(a0, a[i]);
	}

	vector<ll> b(n);
	ll b0 = 101;
	for (ll i = 0; i < n; i++)
	{
		cin >> b[i];

		b0 = min(b0, b[i]);
	}

	string res = "No War";

	if (a0 >= b0)
	{
		res = "War";
	}

	if (b0 <= x)
	{
		res = "War";
	}

	if (a0 >= y)
	{
		res = "War";
	}

	println(res);
}
