#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define open(s) freopen( s".in", "r", stdin ), freopen( s".out", "w", stdout )
#define fp( i, b, e ) for ( int i(b), I(e); i <= I; ++i )
#define fd( i, b, e ) for ( int i(b), I(e); i >= I; --i )
#define go( i, b ) for ( int i(b), v(to[i]); i; v = to[i = nxt[i]] )
template<typename T> inline void cmax( T &x, T y ){ x < y ? x = y : x; }
template<typename T> inline void cmin( T &x, T y ){ y < x ? x = y : x; }
#define getchar() ( p1 == p2 && ( p1 = bf, p2 = bf + fread( bf, 1, 1 << 21, stdin ), p1 == p2 ) ? EOF : *p1++ )
char bf[1 << 21], *p1(bf), *p2(bf);
template<typename T>
inline void read( T &x ){ char t(getchar()), flg(0); x = 0;
	for ( ; !isdigit(t); t = getchar() ) flg = t == '-';
	for ( ; isdigit(t); t = getchar() ) x = x * 10 + ( t & 15 );
	flg ? x = -x : x;
}

clock_t t_bg, t_ed;

int N, M, Q;
int s[MAXN][MAXN];
int s1[MAXN][MAXN], s2[MAXN][MAXN];
#define sum( s, a, b, c, d ) ( s[c][d] + s[a-1][b-1] - s[c][b-1] - s[a-1][d] )

int main(){
	t_bg = clock();
	read(N), read(M), read(Q);
	fp( i, 1, N ) fp( j, 1, M ){
		while( (s[i][j] = getchar()) != '0' && s[i][j] != '1' );
		s[i][j] &= 1;
	}
	fp( i, 1, N ) fp( j, 1, M - 1 ) s1[i][j] = s1[i][j - 1] + s1[i - 1][j] - s1[i - 1][j - 1] + (s[i][j] & s[i][j + 1]);
	fp( i, 1, N - 1 ) fp( j, 1, M ) s2[i][j] = s2[i][j - 1] + s2[i - 1][j] - s2[i - 1][j - 1] + (s[i][j] & s[i + 1][j]);
	fp( i, 1, N ) fp( j, 1, M ) s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
	while( Q-- ){
		int a, b, c, d;
		read(a), read(b), read(c), read(d);
		printf( "%d\n", sum(s, a, b, c, d) - sum(s1, a, b, c, d - 1) - sum(s2, a, b, c - 1, d) );
	}
	t_ed = clock();
	fprintf( stderr, "\n========info========\ntime : %.3f\n====================\n", (double)( t_ed - t_bg ) / CLOCKS_PER_SEC );
	return 0;
}
