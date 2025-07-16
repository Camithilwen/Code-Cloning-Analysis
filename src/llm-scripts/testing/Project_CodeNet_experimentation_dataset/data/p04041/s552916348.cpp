#include <bits/stdc++.h>
const int MOD = 1e9 + 7, N = 40, L = 17;
int n, x, y, z, f[ N + 1 ][ 1 << L ];
int main( )
{
 std::ios::sync_with_stdio( false );
 std::cin >> n >> x >> y >> z;
 int mx = ( 1 << ( x + y + z ) ) - 1, ans = 1, haiku = ( ( 1 << ( x + y + z ) ) >> 1 ) | ( ( 1 << ( y + z ) ) >> 1 ) | ( ( 1 << z ) >> 1 );
 f[ 0 ][ 0 ] = 1;
 for( int i = 0; i < n; ++i, ans = ans * 10LL % MOD ) for( int s = 0; s <= mx; ++s )
 {
  if( !f[ i ][ s ] )
   continue;
  for( int j = 1; j <= 10; ++j )
  {
   int trs = ( s << j | ( 1 << j >> 1 ) ) & mx;
   if( ( trs & haiku ) ^ haiku )
    f[ i + 1 ][ trs ] = ( f[ i + 1 ][ trs ] + f[ i ][ s ] ) % MOD;
   }
 }
 int sub = 0;
 for( int i = 0; i <= mx; ++i )
  sub = ( sub + f[ n ][ i ] ) % MOD;
 std::cout << ( ans - sub + MOD ) % MOD;
 return 0;
}