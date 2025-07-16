#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
// }}} 1
// definition {{{ 1
// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)
#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2
// constants {{{ 2
#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
// }}} 2
// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(ll x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {

    int N,K;
    char S[322];
    Scs(S);
    N = strlen(S);
    Scd(K);

    if( K >= N/2 ) {
        printf ("%d\n", N);
        return 0;
    }

    static int dp[301][301][302] = {};

    Rep(ni,N) Rep(mi,N) {
        int mir = N-1-mi;
        bool same = S[ni] == S[mir];
        RRep(ki,K+1){
            // 無変換
            dp[ni+1][mi+1][ki] = max( dp[ni][mi+1][ki], dp[ni+1][mi+1][ki] );
            dp[ni+1][mi+1][ki] = max( dp[ni+1][mi][ki], dp[ni+1][mi+1][ki] );
            dp[ni+1][mi+1][ki] = max( dp[ni][mi][ki]+same, dp[ni+1][mi+1][ki] );
            // 変換
            dp[ni+1][mi+1][ki+1] = max( dp[ni][mi][ki]+1, dp[ni+1][mi+1][ki+1] );
        }
    }

    // Rep(ki,K+1){
    //     Rep(ni,N+1) Rep(mi,N+1){
    //         printf ("%d%s", dp[ni][mi][ki], mi!=N?",":"\n" );
    //     }
    //     printf ("---\n");
    // }

    int ans = 0;
    Rep(ni,N+1) Rep(mi,N+1){
        if( ni + mi > N ) break;
        Rep(ki,K+1){
            ans = max( dp[ni][mi][ki]*2+(ni+mi<N), ans );
        }
    }
    printf ("%d\n", ans );

    return 0;
}

/**
atcodergrandcontest
atcoder
g
atsetnocdn
 *
 */

