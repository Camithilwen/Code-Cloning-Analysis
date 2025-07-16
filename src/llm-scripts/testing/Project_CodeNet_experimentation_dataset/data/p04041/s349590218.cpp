#include <cstdio>

const int mod = 1e9 + 7;
const int MAXN = 45, MAXS = ( 1 << 17 ) + 5;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

int f[MAXN][MAXS];
int N, X, Y, Z, st, all;

int bit( const int i ) { return 1 << i - 1; }
bool chk( const int S ) { return ( S & st ) == st; }
void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }
int insert( const int S, const int v ) { return ( S << v | bit( v ) ) & all; }

int main()
{
	read( N ), read( X ), read( Y ), read( Z );
	int up = 1 << X + Y + Z;
	all = ( bit( X + Y + Z ) << 1 ) - 1;
	st = bit( Z ) | bit( Y + Z ) | bit( X + Y + Z );
	
	f[0][0] = 1;
	for( int i = 0 ; i < N ; i ++ )
		for( int S = 0 ; S < up ; S ++ )
			if( f[i][S] && ! chk( S ) )
				for( int k = 1, T ; k <= 10 ; k ++ )
					if( ! chk( T = insert( S, k ) ) )
						add( f[i + 1][T], f[i][S] );
	int ans = 1;
	for( int i = 1 ; i <= N ; i ++ )
		ans = 10ll * ans % mod;
	for( int S = 0 ; S < up ; S ++ )
		if( ! chk( S ) )
			add( ans, mod - f[N][S] );
	write( ans ), putchar( '\n' );
	return 0;
}