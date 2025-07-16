//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 305
#define MOD 998244353
using namespace std;
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
typedef long long i64;

i64 N, sum;
i64 a[MAX];
i64 memo[MAX][90005];

i64 dp( i64 x , i64 s )
{
    if( x > N )
    {
        if( s >= ( sum + 1 ) / 2 )
            return 1;
        return 0;
    }
    if( memo[x][s] != -1 )
        return memo[x][s];
    
    i64 ans = 0;
    ans += 2 * dp( x + 1 , s );
    ans += dp( x + 1 , s + a[x] );
    ans %= MOD;
    return memo[x][s] = ans;
}

i64 dp2( i64 x , i64 s )
{
    if( x > N )
    {
        if( s == sum / 2 )
            return 1;
        return 0;
    }
    if( memo[x][s] != -1 )
        return memo[x][s];
    i64 ans = dp2( x + 1 , s ) + dp2( x + 1 , s + a[x] );
    ans %= MOD;
    return memo[x][s] = ans;
}

int main()
{
    optimiza_io 
    memset( memo , -1 , sizeof memo );
    cin >> N;
    i64 ansi = 1;
    for( i64 i = 1; i <= N; i ++ )
    {
        cin >> a[i];
        sum += a[i];
        ansi *= 3;
        ansi %= MOD;
    }
    i64 tmp = 3 * dp( 1 , 0 );
    if( sum % 2 == 0 )
    {
        memset( memo , -1 , sizeof memo );
        tmp -= 3 * dp2( 1 , 0 );
        tmp %= MOD;
        tmp += MOD;
        tmp %= MOD;
    }
    
    cout << ( ( ( ansi - tmp ) % MOD ) + MOD ) % MOD << "\n";
    return 0;
}