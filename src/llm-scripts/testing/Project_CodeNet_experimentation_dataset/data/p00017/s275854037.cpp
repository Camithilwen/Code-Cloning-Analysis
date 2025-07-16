#include <iostream>
#include <string>
using namespace std;

enum eKey{
	ENCYPTION,
	CONJUGATED,
};

void conv( string& s, int i, eKey e ){
	if ( e == CONJUGATED ){
		i = 26 - i;
	}
	for( unsigned j = 0; j < s.size(); ++j ){
		if ( s[ j ] >= 'a' && s[ j ] <= 'z' ){
			s[ j ] = ( s[ j ] - 'a' + i ) % 26 + 'a';
		}
	}
}

int main(){
	string s, sThe, sThis, sThat;
	while ( getline ( cin, s ) ){

		for( int i = 0; i < 26; ++i ){
			sThe = "the";
			sThis = "this";
			sThat = "that";
			conv( sThe, i , ENCYPTION );
			conv( sThis, i , ENCYPTION );
			conv( sThat, i , ENCYPTION );
			if ( s.find( sThe ) != string::npos ||
				 s.find( sThis ) != string::npos ||
				 s.find( sThat ) != string::npos ){
					conv( s, i, CONJUGATED );
					break;
			}
		}
			cout << s << endl;
	}

	return 0;
}