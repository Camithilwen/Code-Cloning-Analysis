//include
//------------------------------------------
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

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

#include <stdexcept>

using namespace std;

// type alias
using ll = long long;
using ull = unsigned long long;

//conversion
//------------------------------------------
inline int toint(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class t> inline string tostring(t x) { ostringstream sout; sout << x; return sout.str(); }

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl
#define DEBUG(x) cerr << #x << " = " << (x) << " (l" << __line__ << ")" << " " << __file__ << endl

inline ll floor(ll a, ull b)
{
	ll llb = b;
	if (a >= 0)
	{
		return a / llb;
	}
	else
	{
		return - ( (-a + llb - 1) / llb);
	}
}

inline ll ceil(ll a, ull b)
{
	ll llb = b;
	if (a >= 0)
	{
		return (a + llb - 1) / llb;
	}
	else
	{
		return - (-a / llb);
	}
}

inline ll getLowestOneBit(ll a)
{
	return a & (-a);
}

inline ll getHighestOneBit(ll a)
{
	while ((a & (a - 1)) != 0)
	{
		a = a & (a - 1);
	}
	return a;
}

inline bool isPower2(ull a)
{
	if (a == 0)
	{
		return false;
	}
	return !(a & (a - 1));
}

inline ll getSpecifiedBit(ll a, unsigned bit)
{
	return (a & (1LL << bit)) >> bit;
}

// computational complexity: o(log(max(a, b))) 
inline ull getGcd(ull a, ull b)
{
	if (b == 0)
	{
		return a;
	}
	return getGcd(b, a % b);
}

template<class Integer>
inline Integer getPower(Integer base, ull exponential)
{
	Integer result = 1;
	while (exponential >= 1)
	{
		if (exponential & 1)
		{
			result = result * base;
		}
		base = base * base;
		exponential >>= 1;
	}

	return result;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<vector<ll>> As(N, vector<ll>(60));
	vector<ll> bit_count(60);
	ll a;
	for (ll i = 0; i < N; ++i)
	{
		cin >> a;
		for (ll j = 0; j < 60; ++j)
		{
			As[i][j] = (a & (1LL << j)) >> j;
			bit_count[j] += (a & (1LL << j)) >> j;
		}
	}

	ll res = 0;
	for (ll j = 0; j < 60; ++j)
	{
		if (bit_count[j] % 2 != 0)
		{
			res += 1LL << j;
			for (ll i = 0; i < N; ++i)
			{
				As[i][j] = 0;
			}
		}
	}

	ll row = 0;
	for (ll j = 59; j >= 0; --j)
	{
		if (bit_count[j] % 2 != 0) continue;
		for (ll i = row; i < N; ++i)
		{
			if (As[i][j] == 0) continue;
			vector<ll> temp = As[row];
			As[row] = As[i];
			As[i] = temp;
			for (ll k = row + 1; k < N; ++k)
			{
				if (As[k][j] == 0) continue;
				for (ll l = 0; l < 60; ++l)
				{
					As[k][l] = (As[k][l] - As[row][l] + 2LL) % 2LL;
				}
			}
			++row;
			break;
		}
	}

	vector<ll> f2_vec(60);
	row = 0;
	for (ll j = 59; j >= 0; --j)
	{
		if (As[row][j] == 0) continue;
		if (f2_vec[j] == 0)
		{
			for (ll k = 0; k < 60; ++k)
			{
				f2_vec[k] = (f2_vec[k] + As[row][k] + 2LL) % 2;
			}
		}
		++row;
	}

	for (ll j = 0; j < 60; ++j)
	{
		if (f2_vec[j] == 1)
		{
			res += (1LL << j) * 2;
		}
	}

	cout << res << endl;

	return 0;
}
