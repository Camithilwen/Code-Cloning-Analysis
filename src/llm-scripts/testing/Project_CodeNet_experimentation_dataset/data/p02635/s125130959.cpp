#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
const int mod = 998244353;
inline int pls( int a , int b ) { a += b - mod; return a + ( a >> 31 & mod ); }
inline int mns( int a , int b ) { a -= b; return a + ( a >> 31 & mod ); }
inline void inc( int & a , int b ) { a += b - mod; a += a >> 31 & mod; }
inline void dec( int & a , int b ) { a -= b; a += a >> 31 & mod; }
inline int fpow( int base , int k ) {
  int res = 1;
  while( k ) {
    if( k & 1 ) res = (lol)res * base % mod;
    base = (lol)base * base % mod; k >>= 1;
  }
  return res;
} int _w;

const int N = 3e2 + 5;

int f[N][N][N] , n , k , sum[N] , m , ss[N];
char str[N];

int main( void ) {
  _w = scanf("%s%d",str+1,&k);
  n = strlen( str + 1 );
  str[n + 1] = '0';
  for( int i = 0 , r ; i <= n ; i = r ) {
    r = i + 1;
    while( r <= n && str[r] != '0' ) ++r;
    sum[++m] = r - i - 1;
  }
  for( int i = m ; i ; --i ) ss[i] = ss[i + 1] + sum[i];
  k = min( k , ss[1] );
  f[0][0][0] = 1;
  for( int i = 1 , s = 0 ; i <= m ; s += sum[i] , ++i ) 
    for( int j = s ; j <= ss[1] ; ++j )
      for( int l = 0 ; l <= k ; ++l ) if( f[i - 1][j][l] ) 
        for( int p = 0 ; p + j <= ss[1] && l + p - sum[i] <= k ; ++p ) {
          inc( f[i][j + p][l + max( p - sum[i] , 0 )] , f[i - 1][j][l] );
        }
  int ans = 0;
  for( int i = 0 ; i <= k ; ++i )
    inc( ans , f[m][ss[1]][i] );
  printf("%d",ans);
  return 0;
}
