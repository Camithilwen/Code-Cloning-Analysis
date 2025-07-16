#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 4000 + 5 ; 
const int P = 998244353 ; 
int maxn, n, K, C[N][N], Ans[N] ; 
signed main()
{
	K = gi(), n = gi(), maxn = n + K ; 
	C[0][0] = 1 ; 
	rep( i, 1, maxn ) rep( j, 0, maxn ) C[i][j] = (!j) ? 1 : ( C[i - 1][j - 1] + C[i - 1][j] ) % P ; 
	for( re int i = 2; i <= 2 * K; ++ i ) {
		int u = 0, v = 0 ; 
		rep( j, 1, K ) 
			if( ((i - j) != j) && ( (i - j) <= K ) && ( (i - j) >= 1 ) ) ++ u ; 
			else if( (i - j) != j ) ++ v ;
		u /= 2, v += u ; 
		if( i % 2 == 0 ) ++ u ; 
		for( re int j = 0; j <= n; ++ j ) {
			Ans[i] = ( Ans[i] + C[u][j] * C[(n - j) + v - 1][(n - j)] % P ) % P ;
		}
	}
	rep( i, 2, 2 * K ) printf("%lld\n", Ans[i] ) ;
	return 0 ;
}