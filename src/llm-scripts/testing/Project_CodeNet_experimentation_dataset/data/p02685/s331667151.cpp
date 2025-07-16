#include <bits/stdc++.h>
#define MOD 998244353
using namespace std ;
int n , m , k ;
int jc[ 200005 ] ;
int ans = 0 ;
inline int qpow ( int a , int b ) {
    int res = 1 ;
    while ( b ) {
        if ( b & 1 ) res = 1LL * res * a % MOD ;
        b >>= 1 ;
        a = 1LL * a * a % MOD ;
    }
    return res % MOD ;
}
inline void init () {
    jc[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; i ++ ) jc[ i ] = 1LL * jc[ i - 1 ] * i % MOD ;
}
inline int inv ( int a ) { return qpow ( a , MOD - 2 ) ; }
inline int C ( int n , int m ) { return 1LL * jc[ n ] * inv ( 1LL * jc[ m ] * jc[ n - m ] % MOD ) % MOD ; }
signed main () {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    init () ;
    for ( int i = 0 ; i <= k ; i ++ ) {
        ans = ( ans + 1LL * m * C ( n - 1 , i ) % MOD * qpow ( m - 1 , n - i - 1 ) % MOD ) % MOD ;
    }
    printf ( "%d\n" , ans % MOD ) ;
    return 0 ;
}
/*
题目简述：
给 n 个方格染 m 种颜色，要求最多有 k 组块相连且颜色相同，求方案数对 998244353 取模的结果。
*/
