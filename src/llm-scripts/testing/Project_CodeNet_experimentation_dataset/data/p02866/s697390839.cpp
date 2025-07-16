#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 998244353;

class ModCalc
{
	LLONG m_mod = MOD;
	vector<LLONG> m_fac;
	vector<LLONG> m_ifac;

public:
	ModCalc(const LLONG mod)
	{
		m_mod = mod;
	}

	// Combinationを計算したいときの前処理：O(max)
	ModCalc(const int max, const LLONG mod)
	{
		m_mod = mod;
		m_fac = vector<LLONG>(max + 1);
		m_ifac = vector<LLONG>(max + 1);
		m_fac[0] = m_ifac[0] = 1;
		for (int i = 0; i < max; ++i)
		{
			m_fac[i + 1] = m_fac[i] * (i + 1) % mod;    // n! (mod M)
			m_ifac[i + 1] = m_ifac[i] * ModPow(i + 1, mod - 2) % mod;   // k!^(M-2) (mod M)
		}
	}

	const LLONG ModAdd(LLONG a, LLONG b) const
	{
		return (a + b) % m_mod;
	}

	const LLONG ModSubtract(LLONG a, LLONG b) const
	{
		LLONG diff = a - b;
		return diff >= 0 ? diff : diff + m_mod;
	}

	const LLONG ModMulti(LLONG a, LLONG b) const
	{
		LLONG prod = a * b % m_mod;
		return prod >= 0 ? prod : prod + m_mod;
	}

	const LLONG ModDiv(LLONG a, LLONG b) const
	{
		LLONG c = m_mod, u = 1, v = 0;
		while (c)
		{
			LLONG t = b / c;
			b -= t * c; swap(b, c);
			u -= t * v; swap(u, v);
		}
		u %= m_mod;
		if (u < 0) u += m_mod;
		return (a % m_mod) * u % m_mod;
	}

	const LLONG ModPow(LLONG x, LLONG n) const
	{
		LLONG ret = 1;
		while (n != 0)
		{
			if (n & 1) ret = ret * x % m_mod;
			x = x * x % m_mod;
			n = n >> 1;
		}
		return ret;
	}

	const LLONG ModComb(LLONG n, LLONG r) const
	{
		if (n == 0 && r == 0) return 1;
		if (n < r || n < 0) return 0;
		LLONG tmp = m_ifac[n - r] * m_ifac[r] % m_mod;
		return tmp * m_fac[n] % m_mod;
	}
};

int main()
{
	int N; cin >> N;
	vector<int> ds(N); REP(i, N) cin >> ds[i];
	map<int, int> d2NumMap;
	REP(i, N)
	{
		++d2NumMap[ds[i]];
	}
	if (ds.front() != 0 || d2NumMap[0] > 1)
	{
		cout << 0 << endl;
	}
	else
	{
		int maxD = d2NumMap.rbegin()->first;
		LLONG ans = 1;
		ModCalc mod(MOD);
		for (int d = 1; d <= maxD; ++d)
		{
			if (d2NumMap.count(d) == 0)
			{
				ans = 0;
				break;
			}

			ans = mod.ModMulti(ans, mod.ModPow(d2NumMap[d - 1], d2NumMap[d]));
		}
		cout << ans << endl;
	}
}
