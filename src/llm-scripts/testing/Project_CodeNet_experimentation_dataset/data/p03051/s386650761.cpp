#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()

#define cMOD 1000000007ll
constexpr int cN = ( 1 << 20 ) + 1;
ll pool0[cN];
ll pool1[cN];
ll poolCount[cN];

ll fib( ll a )
{
	ll b = 1; ll c = 1;
	REP( i, a - 2 )
	{
		ll d = c;
		c = ( c + b ) % cMOD;
		b = d;
	}
	return c;
}

template <typename T>
T mod_pow(T x, T n, T mod)
{
	T res = 1;
	while (n > 0)
	{
		if (n & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	memset( pool0, 0, sizeof( pool0 ) );
	memset( pool1, 0, sizeof( pool1 ) );
	memset( poolCount, 0, sizeof( poolCount ) );
	
	ll n;
	cin >> n;
	vector<ll> v(n,0);

	ll sum = 0;
	REP(i,n)
	{
		cin >> v[i];
		sum ^= v[i];
	}

	ll left = 0;
	ll count = 0;
	REP(i,cN) pool0[i] = 1;
	REP(i,n)
	{
		left ^= v[i];
		if( left == 0 ) ++count;
		else
		{
			pool0[left] = ( pool0[left] + pool1[left] * ( count - poolCount[left] ) ) % cMOD;
			poolCount[left] = count;
			pool1[left] = ( pool1[left] + pool0[left] ) % cMOD;
		}
	}

	ll ans = 0;
	if( sum == 0 )
	{
		ans = mod_pow( 2ll, count - 1, cMOD );
		REP(i, cN)
		{
			if( i == 0 ) continue;
			ans = ( ans + pool1[i] ) % cMOD;
		}
	}
	else
	{
		ans = pool0[sum];
	}
	
	cout << ans << endl;

	return 0;
}