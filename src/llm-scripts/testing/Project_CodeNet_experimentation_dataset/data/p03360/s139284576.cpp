#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <set>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a , b , c , k;
    cin >> a >> b >> c >> k;
    cout << a + b + c - max( a , max( b , c ) ) + max( a , max( b , c ) ) * pow( 2 , k );
}
