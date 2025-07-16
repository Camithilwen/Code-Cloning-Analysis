#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	string ans = "AC";
	if( S[0] != 'A' ) ans = "WA";
	else {
		string s = S.substr( 2, S.size() - 2 - 1 );
		int n = s.find( 'C' );
		if( n == string::npos ) ans = "WA";
		else if( s.find( 'C', n + 1 ) != string::npos ) ans = "WA";
		else {
			for( int i = 0; i < S.size(); i++ ) {
				if( i == 0 || S[i] == 'C' && 2 <= i && i <= S.size() - 2 ) continue;
				if( islower( S[i] ) == false ) ans = "WA";

			}
		}
	}

	cout << ans << endl;
}
