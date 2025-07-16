
#include <cstdio>

const int MAXN = 6005;

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

int f[MAXN][MAXN << 1];
int N, M;

void add( int &x, const int v ) { x += v; if( x >= M ) x -= M; }

int main()
{
	read( N ), read( M );
	int t = N * 3;
	f[0][t] = 1;
	for( int i = 1 ; i <= t ; i ++ )
		for( int j = - t ; j <= t ; j ++ )
		{
			if( j > -t ) add( f[i][j + t], f[i - 1][j + t - 1] ); //长度为1
			if( j < t && i >= 2 ) add( f[i][j + t], 1ll * f[i - 2][j + t + 1] * ( i - 1 ) % M ); //长度为2
			if( i >= 3 ) add( f[i][j + t], 1ll * f[i - 3][j + t] * ( i - 1 ) % M * ( i - 2 ) % M ); //长度为3 
		}
	int ans = 0;
	for( int i = 0 ; i <= t ; i ++ ) add( ans, f[t][i + t] );
	write( ans ), putchar( '\n' );
	return 0;
}