#include <bits/stdc++.h>
using namespace std ;

const int N = 5010 ;
const long long inf = 10000000000000000 ;
pair<int,int> zab [ N ] ;

bool cmp ( pair<int,int> A, pair<int,int> B ) {
    return A.first + A.second < B.first + B.second ;
}

long long dp [ N ][ 3 ];

int main() {
 //   freopen("input.txt", "r", stdin) ;
    int n ; cin >> n ;
    for ( int i = 0 ; i < n ; ++i )
        cin >> zab[i].first >> zab[i].second ;
    sort ( zab, zab+n, cmp ) ;
    int ans =0 ;
    for ( int i = 1 ; i <= n ; ++i ) {
        for ( int j = 0 ; j < n ; ++j ) {
            if ( i == 1 ) dp[j][i%2] = zab[j].first ;
            else if ( j + i <= n ) dp[j][i%2] = min ( 1ll*zab[j].first, dp[j+1][(i-1)%2] - zab[j].second );
            else dp[j][i%2] = -inf ;
        }
        bool kPosible = (dp[n-1][i%2] >= 0ll) ;
        for ( int j = n-2 ; j >= 0 ; --j ) {
            dp[j][i%2] = max ( dp[j][i%2], dp[j+1][i%2] ) ;
            kPosible |= (dp[j][i%2]>=0ll) ;
        }
        if ( kPosible ) ans = i ;
    }
    cout << ans << '\n' ;
}
