#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h , w;
    string s[50] = {};
    cin >> h >> w;
    for( int i = 0 ; i < h ; i++ ) cin >> s[i];
    for( int i = 0 ; i < h ; i++ ) {
    	for ( int j = 0 ; j < w ; j++ ) {
    		if ( s[i][j] == '#' ) {
        		bool y = 0;
        		if ( i && s[i - 1][j] == '#' ) y = 1;
        		if ( i + 1 < h && s[i + 1][j] == '#' ) y = 1;
        		if ( j && s[i][j - 1] == '#' ) y = 1;
        		if ( j + 1 < w && s[i][j + 1] == '#' ) y = 1;
        		if ( !y ) {
					cout << "No";
					return 0;
				}
			}
		}
    }
    cout << "Yes";
}
