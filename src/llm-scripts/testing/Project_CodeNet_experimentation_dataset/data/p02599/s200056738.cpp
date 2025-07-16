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

template<class Integer>
class BinaryIndexedTree
{
private:
	ull maxSize_;
	vector<Integer> values_;
public:
	BinaryIndexedTree(ull maxSize) : maxSize_(maxSize), values_(maxSize_, 0) {}

	void update(ll index, Integer increment)
	{
		if (maxSize_ <= index)
		{
			throw invalid_argument("Index should be less than maxSize.");
		}
		++index;

		while (index <= maxSize_)
		{
			values_[index - 1] += increment;
			index += index & -index;
		}
	}

	Integer query(ll index)
	{
		if (maxSize_ <= index)
		{
			throw invalid_argument("Index should be less than maxSize.");
		}
		++index;

		Integer res = 0;
		while (index > 0)
		{
			res += values_[index - 1];
			index -= index & -index;
		}
		return res;
	}
};
using bit = BinaryIndexedTree<ll>;

int solve() {
	ll n, q;
	cin >> n >> q;

	vector<ll> as(n);
	vector<tuple<ll, ll, ll>> rlis;
	ll l, r;
	REPD(i, 0, n) cin >> as[i];
	REPD(i, 0, q){
		cin >> l >> r;
		--l, --r;
		rlis.emplace_back(r, l, i);
	}
	sort(rlis.begin(), rlis.end());

	bit counters(n);
	map<ll, ll> color_to_max_idx;
	vector<ll> results(q);
	ll idx, curr_r = 0;
	REPD(i, 0, q) {
		tie(r, l, idx) = rlis[i];
		while(curr_r <= r) {
			counters.update(curr_r, 1LL);
			if (color_to_max_idx.count(as[curr_r]) != 0LL) {
				counters.update(color_to_max_idx[as[curr_r]], -1LL);
			}
			color_to_max_idx[as[curr_r]] = curr_r;
			++curr_r;
		}
		results[idx] = counters.query(r) - (l > 0LL ? counters.query(l - 1LL) : 0LL);
	}

	REPD(i, 0, q) cout << results[i] << endl;

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
