#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;
const int MAXN = 3e5 + 5;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int f[MAXN][3][3];
char S[MAXN];
int N;

int add( int &x, const int y ) { return x = ( x + y >= mod ? x + y - mod : x + y ); }

int main()
{
	scanf( "%s", S + 1 );
	f[0][0][0] = 1, N = strlen( S + 1 );
	for( int i = 0 ; i < N ; i ++ )
		for( int j = 0 ; j < 3 ; j ++ )
			for( int k = 0 ; k < 3 ; k ++ )
				if( f[i][j][k] )
				{
					if( S[i + 1] ^ '1' ) add( f[i + 1][j][k == 2 ? 1 : k + 1], f[i][j][k] );
					if( S[i + 1] ^ '0' ) 
					{
						if( k ) add( f[i + 1][j][k - 1], f[i][j][k] );
						else add( f[i + 1][MIN( j + 1, 2 )][k], f[i][j][k] );
					}
				}
	write( add( f[N][1][0], add( f[N][2][0], add( f[N][2][1], f[N][2][2] ) ) ) ), putchar( '\n' );
	return 0;
}