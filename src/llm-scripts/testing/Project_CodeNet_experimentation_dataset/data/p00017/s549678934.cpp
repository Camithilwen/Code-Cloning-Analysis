#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[])
{
	string str;

	while( getline( cin, str ) ){
		for( int i = 0;i < 26;i++ ){
			for( int j = 0;j < str.size();j++ ){
				if( str[j] >= 'a' && str[j] <= 'y' ) str[j]++;
				else if( str[j] == 'z' ) str[j] = 'a';
			}
			if( str.find( "the" ) != string::npos || str.find( "this" ) != string::npos || str.find( "that" )  != string::npos ) {cout << str << endl; break;}
		}
	}
	return 0;
}