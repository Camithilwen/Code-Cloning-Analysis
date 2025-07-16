#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
using namespace std;

ll n,arr[200010],a,b,c,ans=1e18,s1,s2,s3,s4;

ll sum( ll l , ll r ){ return arr[r]-arr[l-1]; }

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(ll i=1; i<=n; i++) cin >> arr[i] , arr[i]+=arr[i-1];

    a = 1;
    c = 3;
    for(b=2; b<n-1; b++){

        while( a+1 < b && abs( sum( 1 , a+1 )-sum( a+2 , b ) ) <= abs( sum( 1 , a ) - sum( a+1 , b ) ) ) a++;
        while( c <= b ) c++;
        while( c+1 < n && abs( sum( b+1 , c+1 )-sum( c+2 , n ) ) <= abs( sum( b+1 , c ) - sum(c+1,n)) ) c++;

        s1 = sum( 1 , a );
        s2 = sum( a+1 , b );
        s3 = sum( b+1 , c );
        s4 = sum( c+1 , n );

        //cout << a << " " << b << " " << c << " " << s1 << " " << s2 << " " << s3 << " " << s4 << "\n";

        ans = min( ans , max( max( s1 , s2 ) , max( s3 , s4 ) ) - min( min( s1 , s2 ) , min( s3 , s4 ) ) );

    }

    cout << ans;

    return 0;
}
