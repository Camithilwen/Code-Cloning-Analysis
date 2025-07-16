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
    int n;
    cin >> n;
    string a = "";
    while( n != 0 ) {
        int r = n % 2;
        if( r == -1 ) r = 1;
        a += r + '0';
        n = ( n - r ) / ( -2 );
    }
    reverse( a.begin() , a.end() );
    if( a == "" ) cout << '0';
    else cout << a;
}