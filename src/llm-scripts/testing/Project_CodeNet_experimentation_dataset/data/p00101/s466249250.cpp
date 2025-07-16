#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;

	cin >> n;
	cin.get();

	for( int i = 0; i < n; ++i ){
		string s;
		getline( cin, s );
		int index = 0;
		while( ( index = s.find( "Hoshino", index ) ) != string::npos ){
			s.replace( index, 7, "Hoshina" );
			index += 7;
		}
		cout << s << endl;
	}

	return 0;
}