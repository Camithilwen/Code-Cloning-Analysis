#include <iostream>
#include <cstdio>
#include <algorithm>
#include <array>
#include <vector>
#include <functional>

using namespace std;

int main() {
  while( true ) {
	int n, m;
	cin >> n >> m;
	if ( n == 0 && m == 0 ) break;

	vector<int> xs( n );
	for ( int i = 0; i < n; i++ ) {
	  cin >> xs[ i ];
	}
	sort( xs.begin(), xs.end(), greater<int>() );
	
	int sum = 0;
	for ( int i = 0; i < n; i++ ) {
	  sum += ( (i + 1) % m == 0 ? 0 : xs[ i ] );
	}
	cout << sum << endl;
  }  
}