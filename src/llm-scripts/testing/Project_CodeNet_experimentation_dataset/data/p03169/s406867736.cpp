#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <iomanip>
#include <complex>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const int N = 3e2 + 5, inf = 1e9, mod = 998244353;
using namespace std;

int n, a, freq[4] = {};
ld dp[N][N][N] = {};
bool vis[N][N][N] = {};

ld solve ( int c1 , int c2 , int c3 )
{
    if ( c1 + c2 + c3 == 0 )
        return 0;
    if ( vis[c1][c2][c3] )
        return dp[c1][c2][c3];
    vis[c1][c2][c3] = true;
    ld ret = 1.0, c0 = n - ( c1 + c2 + c3 );
    if ( c1 )
        ret += solve ( c1 - 1 , c2 , c3 ) * ( 1.0 * c1 / n );
    if ( c2 )
        ret += solve ( c1 + 1 , c2 - 1 , c3 ) * ( 1.0 * c2 / n );
    if ( c3 )
        ret += solve ( c1 , c2 + 1 , c3 - 1 ) * ( 1.0 * c3 / n );
    ret /= ( 1 - ( c0 / n ) );
    return dp[c1][c2][c3] = ret;
}

int main()
{
    IO
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;
    }
    cout << fixed << setprecision(10) << solve( freq[1] , freq[2] , freq[3] ) << '\n';
    return 0;
}