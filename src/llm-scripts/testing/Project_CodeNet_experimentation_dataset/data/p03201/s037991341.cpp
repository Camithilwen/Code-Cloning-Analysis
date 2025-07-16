//include
//------------------------------------------
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>

#include <numeric>
#include <utility>
#include <complex>

#include <sstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>

// namespace
using namespace std;

// type alias
using ll = long long;
using ull = unsigned long long;
using comp = complex<double>;

// constant
static const ll MOD = 1000000007LL;
static const double PI = 3.14159265358979323846;

// conversion
inline ll toint(string s) { ll v; istringstream sin(s); sin >> v; return v; }
template<class t> inline string tostring(t x) { ostringstream sout; sout << x; return sout.str(); }

// print
#define RET(x) return cout << x << endl, 0;

// for loop
#define REP(i, a, b) for ((i) = (ll)(a);(i) < (ll)(b);(i)++)
#define REPD(i, a, b) for (ll i = (ll)(a);(i) < (ll)(b);(i)++)
#define REPI(v, vs) for (auto& v : vs)

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl
#define DEBUG(x) cerr << #x << " = " << (x) << " (l" << __LINE__ << ")" << " " << __FILE__ << endl

#define MAX_VALUE 9223372036854775807

inline ll get_highest_one_bit(ll a)
{
	while ((a & (a - 1)) != 0)
	{
		a = a & (a - 1);
	}
	return a;
}

int solve() {
	ll N;
	cin >> N;

	map<ll, ll> val_to_count;
	ll a, b;
	REPD(i, 0, N) {
		cin >> a;
		if (val_to_count.count(a) == 0) val_to_count[a] = 0;
		++val_to_count[a];
	}

	ll res = 0;
	vector<bool> used(N, false);
	for (auto iter = val_to_count.end(); iter != val_to_count.begin(); ) {
		--iter;
		a = iter->first;
		b = get_highest_one_bit(a) * 2LL - a;
		if (val_to_count[a] == 0) continue;
		if (val_to_count.count(b) > 0) {
			if (a != b) {
				ll count = min(val_to_count[a], val_to_count[b]);
				val_to_count[a] -= count;
				val_to_count[b] -= count;
				res += count;
			}
			else {
				ll count = val_to_count[a] / 2LL;
				val_to_count[a] -= count * 2LL;
				res += count;
			}
		}
	}

	RET(res);

	return 0;
}

//main function
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve();
	// ll t;
	// cin >> t;
	// REPD(i, 0, t) solve();

	return 0;
}
