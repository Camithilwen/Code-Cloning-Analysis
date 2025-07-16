#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <queue>
#include <tuple>
#include <regex>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#include <cstring>

using namespace std;

template<typename T> bool chmax( T &a, const T b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using ll = long long;
using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;

#define eb emplace_back
#define pb push_back
#define mp make_pair

#define F first
#define S second

#define popcnt __builtin_popcountll

#define rep( i, n ) for ( ll i = 0; i < (ll)( n ); ++i )
#define reps( i, n ) for ( ll i = 1; i <= (ll)( n ); ++i )
#define rrep( i, n ) for ( ll i = (ll)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( ll i = (ll)( ( n ) ); i > 0; --i )
#define arep( i, v ) for ( auto &&i : ( v ) )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();
template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }


int main()
{
	ll n; cin >> n;
	vector<vector<ll>> cnt( 20, vector<ll>( 20 ) );
	vector<ll> v;

	rep( i, n )
	{
		string s; cin >> s;
		string t = "", u = "";
		auto idx = string::npos;
		if ( ( idx = s.find( "." ) ) != string::npos )
		{
			t = s.substr( 0, idx );
			u = s.substr( idx + 1 );
			while ( u.length() < 9 ) u += "0";
		}
		else
		{
			t = s;
			u = "0";
		}

		v.eb( atoll( t.c_str() ) * 1e9 + atoll( u.c_str() ) );
	}

	arep( it, v )
	{
		ll tcnt = 0, fcnt = 0;
		while ( it % 2 == 0 && tcnt < 18 )
		{
			it /= 2;
			++tcnt;
		}
		while ( it % 5 == 0 && fcnt < 18 )
		{
			it /= 5;
			++fcnt;
		}

		++cnt[tcnt][fcnt];
	}

	ll ans = 0;
	rep( i, 19 )
	{
		rep( j, 19 )
		{
			rep( k, 19 )
			{
				rep( l, 19 )
				{
					if ( i + k < 18 || j + l < 18 )
						continue;
					if ( i == k && j == l )
						ans += cnt[i][j] * ( cnt[k][l] - 1 );
					else
						ans += cnt[i][j] * cnt[k][l];
				}
			}
		}
	}

	cout << ans / 2 << endl;

	return ( 0 );
}
