#include <iostream>
#include <vector>
using namespace std;

int main() {

  while( true ) {

    long long int a, b, c;
    cin >> a >> b >> c;
    if ( a == 0 ) break;

    vector< long long int > ans;
    for ( long long int i = 0; i < a + b + c; i++ ) {
      ans.push_back( 2 );
    }

    long long int n;
    cin >> n;

    vector< long long int > v_a, v_b, v_c;

    for ( long long int i = 0; i < n; i++ ) {

      long long int in_a, in_b, in_c, r;
      cin >> in_a >> in_b >> in_c >> r;

      if ( r == 1 ) {
	ans[ in_a - 1 ] = 1;
	ans[ in_b - 1 ] = 1;
	ans[ in_c - 1 ] = 1;
      }else {
	v_a.push_back( in_a );
	v_b.push_back( in_b );
	v_c.push_back( in_c );
      }

    }

    for ( long long int i = 0; i < v_a.size(); i++ ) {
      if ( ans[ v_a[i] - 1 ] == 1 && ans[ v_b[i] - 1 ] == 1 ) ans[ v_c[i] - 1 ] = 0;
      if ( ans[ v_a[i] - 1 ] == 1 && ans[ v_c[i] - 1 ] == 1 ) ans[ v_b[i] - 1 ] = 0;
      if ( ans[ v_b[i] - 1 ] == 1 && ans[ v_c[i] - 1 ] == 1 ) ans[ v_a[i] - 1 ] = 0;
    }

    for ( long long int i = 0; i < a + b + c; i++ ) {
      cout << ans[i] << endl;
    }

  }

  return 0;

}