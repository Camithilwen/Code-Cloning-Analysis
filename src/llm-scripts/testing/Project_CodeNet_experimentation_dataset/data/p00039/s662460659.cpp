#include <iostream>
#include <string>

using namespace std;

int main()
{
	string buf;
	
	while (cin >> buf) {
		int amount = 0;
		while ( !(buf.empty()) ) {
			switch ( buf.at(0) ) {
			case 'M':
				buf.erase( buf.begin() ); amount += 1000; break;
			case 'D':
				buf.erase( buf.begin() ); amount += 500; break;
			case 'C':
				if ( buf.size() >= 2 ) {
					if ( buf.at(1) == 'M' ) { buf.erase(0,2); amount += 900; break; }
					else if ( buf.at(1) == 'D' ) { buf.erase(0,2); amount += 400; break; }
				}
				buf.erase( buf.begin() ); amount += 100; break;
			case 'L':
				buf.erase( buf.begin() ); amount += 50; break;
			case 'X':
				if ( buf.size() >= 2 ) {
					if ( buf.at(1) == 'C' ) { buf.erase(0,2); amount += 90; break; }
					else if ( buf.at(1) == 'L' ) { buf.erase(0,2); amount += 40; break; }
				}
				buf.erase( buf.begin() ); amount += 10; break;
			case 'V':
				buf.erase( buf.begin() ); amount += 5; break;
			case 'I':
				if ( buf.size() > 1 ) {
					if ( buf.at(1) == 'X' ) { buf.erase(0,2); amount += 9; break; }
					else if ( buf.at(1) == 'V' ) { buf.erase(0,2); amount += 4; break; }
				}
				buf.erase( buf.begin() ); amount += 1; break;
			}
			// cout << buf << endl;
		}
		cout << amount << endl;
	}	
	
	return 0;
}