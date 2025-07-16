#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd( ll x, ll y );
ll lcm( ll x, ll y );

int main()
{
    int n, c, a[11];

    while ( true ) {
        memset( a, 0, sizeof(a) );
        scanf("%d", &n );
        if ( n == 0 ) break;
        for ( int i = 0; i < n; i++ ) {
            scanf("%d", &c );
            a[c]++;
        }

        for ( int i = 0; i < 10; ++i ) {
            if ( a[i] != 0 ) {
                for ( int j = 0; j < a[i]; ++j ) {
                    printf("*");
                }
            } else {
                printf("-");
            }
            putchar('\n');
        }
    }

    return 0;
}

ll gcd( ll x, ll y )
{
    if ( y == 0 ) return x;
    return gcd( y, x % y );
}

ll lcm( ll x, ll y )
{
    return x / gcd( x, y ) * y;
}

