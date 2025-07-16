#include <bits/stdc++.h>
using namespace std;

string hands( const vector<int>& c ) {
	int n = (int)c.size();

	int p1 = 0;
	int c3 = 0;

	for( int i = 0; i < n; ++i ) {
		if( c[i] == 4 ) {
			return "four card";
		}
		else if( c[i] == 3 ) { c3 += 1; }
		else if( c[i] == 2 ) { p1 += 1; }
	}

	if( c3 > 0 && p1 > 0 ) {
		return "full house";
	}
	else if( c3 > 0 ) {
		return "three card";
	}
	else if( p1 == 2 ) {
		return "two pair";
	}
	else if( p1 == 1 ) {
		return "one pair";
	}

	int x = 0;
	for( int i = 0; i <= n; ++i ) {
		x = (c[i%n] == 1) ? (x+1) : 0;

		if( x == 5 ) { break; }
	}

	return x == 5 ? "straight" : "null";
}

int main() {
	ios_base::sync_with_stdio( false );

	string line;
	while( getline( cin, line ) ) {
		replace( line.begin(), line.end(), ',', ' ' );

		istringstream iss( line );
		vector<int> cnt( 13 );
		int cd;
		while( iss >> cd ) { cnt[cd-1] += 1; }

		cout << hands( cnt ) << '\n';
	}

	return 0;
}

