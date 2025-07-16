#include<bits/stdc++.h>
using namespace std;
int read() {
    char cc = getchar(); int cn = 0, flus = 1;
    while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
    while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
    return cn * flus;
}
const int N = 1000 + 5 ; 
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
int n, m, book[N], w[N][N], vis[N], can[N];   
bool check( int x ) {
    memset( book, 0, sizeof(book) ), memset( can, 0, sizeof(can) ) ;
    int flag ; rep( i, 1, n ) vis[i] = 1, ++ book[w[i][vis[i]]] ; 
    rep( i, 1, m ) {
        flag = 1 ; 
        rep( j, 1, n ) {
            int u = w[j][vis[j]] ; 
            if( book[u] > x ) {
                can[u] = 1; flag = 0 ; 
                while( vis[j] <= n && can[w[j][vis[j]]] ) ++ vis[j] ; 
                if( vis[j] > n ) return 0; 
                ++ book[w[j][vis[j]]] ; 
            }
        }
        if( flag ) return 1; 
    }
    return 0 ; 
}
signed main()
{
    n = read(), m = read() ; 
    rep( i, 1, n ) rep( j, 1, m ) w[i][j] = read() ; 
    int l = 1, r = n, ans = 0, mid ; 
    while( l <= r ) {
        mid = ( l + r ) >> 1 ; 
        if( check(mid) ) ans = mid, r = mid - 1 ; 
        else l = mid + 1 ; 
    }
    printf("%d\n", ans ) ; 
    return 0;
}