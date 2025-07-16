#include <bits/stdc++.h>
#define For( i, j, k ) for( int i = j; i <= k; ++i )
using std::vector;
using std::pair;
using std::cin;
using std::cout;
typedef long long LONG;
typedef int INT;
const INT N = 100100;
char c[ N ];
INT n, ans[ N ];
void Print( )
{
 For( i, 1, n )
  cout << ( ans[ i ] ? 'W' : 'S' );
 return;
}
void INIT( )
{
 For( i, 3, n )
  ans[ i ] = ans[ i - 2 ] ^ ans[ i - 1 ] ^ ( c[ i - 1 ] != 'o' );
 return;
}
bool check( )
{
 bool flag = 0;
 For( i, 1, n )
 {
  int l = ( i - 1 == 0 ) ? n : i - 1, r = ( i + 1 > n ? 1 : i + 1 );
  flag |= ( ans[ l ] ^ ans[ r ] != ( c[ i ] != 'o' ^ ans[ i ] ) );
 }
 return !flag;
}
int main( )
{
 std::ios::sync_with_stdio( false );
 cin >> n;
 cin >> c + 1;
 For( i, 0, 1 ) For( j, 0, 1 )
 {
  ans[ 1 ] = i, ans[ 2 ] = j;
  INIT( );
  if( check( ) )
  {
   Print( );
   return 0;
  }
 }
 cout << "-1";
 return 0;
}
