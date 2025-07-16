#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	string s;
	cin >> s;
	for ( int i = 0 ; i < s.length()-1 ; i++ ) {
		if ( s[i] == s[i+1] ) {
			cout << i + 1 << ' ' << i + 2;
			return 0;
		}
		else if ( s[i] == s[i+2] ) {
			cout << i + 1 << ' ' << i + 3;
			return 0;
		}
	}
	cout << -1 << ' ' << -1;
}