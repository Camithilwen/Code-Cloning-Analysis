#include <bits/stdc++.h>

#define gc( ) std::getchar( )
#define pc( i ) std::putchar( i )

template < typename T >
inline T read( )
{
	register T x = 0;
	register char ch = gc( );
	register bool f = 0;
	while( !std::isdigit( ch ) )
	{
		f = ( ch == '-' );
		ch = gc( );
	}
	while( std::isdigit( ch ) )
	{
		x = x * 10 + ( ch - '0' );
		ch = gc( );
	}
	return f ? -x : x;
}

template < typename T >
void print( T x )
{
	if( x < 0 )
	{
		x = -x;
		pc( '-' );
	}
	if( x < 10 )
	{
		pc( x + 48 );
		return;
	}
	print < T > ( x / 10 );
	pc( x % 10 + 48 );
	return ;
}

namespace Solution
{
#define IOS std::ios::sync_with_stdio( false ), std::cin.tie( 0 ), std::cout.tie( 0 )
#define Rep( i, j, k ) for( int i = j; i >= k; --i )
#define rdi( ) read < int > ( )
#define rdl( ) read < long long > ( )
#define pti( i ) print < int > ( i ), putchar( ' ' )
#define ptl( i ) print < long long > ( i ), putchar( ' ' )
#define For( i, j, k ) for( int i = j; i <= k; ++i )
	using std::cin;
	using std::cout;
	using std::endl;
	using std::vector;
	using std::map;
	using std::queue;
	using std::deque;
	using std::set;
	using std::pair;
	const int Maxn = 100001;
	int n, bol, L, Q, bl[ Maxn ], x[ Maxn ], to[ Maxn ], nxt[ Maxn ], out[ Maxn ];
	int find( int u )
	{
		int l = u + 1, r = n, ans = u;
		while( l <= r )
		{
			int mid = l + r >> 1;
			if( x[ mid ] - x[ u ] <= L )
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		return ans;
	}
	int solve( int l, int r )
	{
		int res = 0;
		while( bl[ l ] < bl[ r ] )
		{
			res += nxt[ l ];
			l = out[ l ];
		}
		while( l < r )
		{
			res++;
			l = to[ l ];
		}
		return res;
	}
	void fakemain( )
	{
		IOS;
		cin >> n;
		bol = sqrt( n );
		For( i, 1, n )
			cin >> x[ i ],
			bl[ i ] = ( i - 1 ) / bol + 1;
		cin >> L;
		For( i, 1, n )
			to[ i ] = find( i );
		Rep( i, n - 1, 1 )
		{
			if( to[ i ] == n )
			{
				out[ i ] = n;
				nxt[ i ] = 1;
			}
			else
			{
				if( to[ i ] > bol * bl[ i ] )
				{
					out[ i ] = to[ i ];
					nxt[ i ] = 1;
				}
				else
				{
					out[ i ] = out[ to[ i ] ];
					nxt[ i ] = nxt[ to[ i ] ] + 1;
				}
			}
		}
		cin >> Q;
		int l, r;
		while( Q-- )
		{
			cin >> l >> r;
			if( l > r )
				std::swap( l, r );
			cout << solve( l, r ) << '\n';
		}
		return;
	}

} // namespace Solution

int main( int argc, char* argv[] )
{
	Solution::fakemain( );
	return 0;
}