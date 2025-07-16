#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 6.66;
int arr [ MAXN ];
string player[2] = { "First","Second" };

int main ( ) {
  int n; scanf ( "%d",&n ) ;
  for ( int i = 0;i<n;i++ ) scanf ( "%d", arr + i ) ;
  int cnt[2] = { 0 , 0 };
  bool is_one = false;
  for ( int i = 0;i<n;i++ ) cnt[arr[i] % 2 ] ++,is_one |= (arr[i] == 1);
  if ( cnt[0] % 2 == 1 ) { printf ( "First\n" ); return 0; }
  bool turn = 0;
  while ( !is_one && cnt[1] == 1 )
  {
    for ( int i = 0;i<n;i++ ) if ( arr[i] % 2 ) arr[i] -- ;
    int gc = arr[0];
    for ( int i = 0;i<n;i++ ) gc = __gcd ( arr[i], gc );
    for ( int i = 0;i<n;i++ ) arr[i] /= gc;
    cnt[1] = cnt[0] = 0;
    for ( int i = 0;i<n;i++ ) cnt[arr[i] % 2 ] ++,is_one |= (arr[i] == 1);
    turn = !turn ;
  }
  if ( cnt[0] % 2 ) printf ( "%s\n", player[turn].c_str ( ) );
  else printf ( "%s\n", player[!turn].c_str ( ) );
  return 0;
}
