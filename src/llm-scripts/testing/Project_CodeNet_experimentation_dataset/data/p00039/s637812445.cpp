#include <bits/stdc++.h>
using namespace std;

bool match( char ch, const string& p ) {
	for( auto a: p ) {
		if( a == ch ) { return true; }
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio( false );

	string s;
	while( cin >> s ) {
		int n = (int)s.size();
		int result = 0;

		for( int i = n-1; i >= 0; --i ) {
			if( s[i] == 'I' ) {
				result += i < n-1 && s[i+1] != 'I' ? -1 : 1;
			}
			else if( s[i] == 'V' ) {
				result += i < n-1 && match( s[i+1], "XLCDM" ) ? -5 : 5;
			}
			else if( s[i] == 'X' ) {
				result += i < n-1 && match( s[i+1], "LCDM" ) ? -10 : 10;
			}
			else if( s[i] == 'L' ) {
				result += i < n-1 && match( s[i+1], "CDM" ) ? -50 : 50;
			}
			else if( s[i] == 'C' ) {
				result += i < n-1 && match( s[i+1], "DM" ) ? -100 : 100;
			}
			else if( s[i] == 'D' ) {
				result += i < n-1 && match( s[i+1], "M" ) ? -500 : 500;
			}
			else if( s[i] == 'M' ) {
				result += 1000;
			}
		}

		cout << result << endl;
	}

	return 0;
}

