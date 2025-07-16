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
    int a[n] , b[n] , c[n];
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    for( int i = 0 ; i < n ; i++ ) cin >> b[i];
    for( int i = 0 ; i < n ; i++ ) cin >> c[i];
    sort( a , a + n );
    sort( b , b + n );
    sort( c , c + n );
    ll x = 0 , d = 0 , e = 0;
    for( int i = 0 ; i < n ; i++ ) {
        d = 1ll * ( lower_bound( a , a + n , b[i] ) - a );
        e = 1ll * ( n - (upper_bound( c , c + n , b[i] ) - c ) );
        x += d * e;
    }
    cout << x;
}

