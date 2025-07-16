#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define IN freopen("perimetric_chapter_1_input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)

#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG printf("Hi\n")
#define i64 long long int
#define ui64 unsigned long long int
#define xx first
#define yy second
#define ln 17
#define off 2002

#define sq(x) ((x)*(x))

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace __gnu_pbds;
using namespace std ;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int,int> pii;

#define log 20
#define mod 1000000007LL
#define INF 1000000000000000000LL
#define maxn 300005

const long double eps = 1e-9 ;

class numberTheory{

public:
    numberTheory(){}

    pii extendedEuclid(i64 a, i64 b) { // returns x, y | ax + by = gcd(a,b)

        if(b == 0) return pii( a >= 0 ? 1 : -1 , 0LL);
        else {
            pii d = extendedEuclid(b, a % b);
            return pii(d.yy, d.xx - d.yy * (a / b));
        }

    }

    i64 modularInverse(i64 a, i64 n) {
        pair<i64,i64> ret = extendedEuclid(a, n);
        return ((ret.xx % n) + n) % n;
    }


    i64 bigMod(i64 a, i64 n , i64 m)
    {
        if(n==0) return 1 ;
        i64 ret = bigMod(a,n/2,m) ;
        ret = (ret*ret)%m ;
        if(n%2) ret = (ret*a)%m ;
        return ret ;
    }
};

const i64 N = 5000000 ;

i64 fact[N+5] , invFact[N+5] ;

i64 C(i64 n, i64 r)
{
    if( n<0 || r<0 || r>n ) return 0 ;
    i64 ret = (fact[n]*invFact[r])%mod ;
    return (ret*invFact[n-r])%mod ;
}

void preprocess()
{
    numberTheory nt ;

    fact[0] = 1 ;
    for(i64 x=1 ; x<=N ; x++) fact[x] = (fact[x-1]*x)%mod ;

    invFact[N] = nt.modularInverse(fact[N],mod) ;

    for(i64 x=N-1 ; x>=0 ; x--) invFact[x] = (invFact[x+1]*(x+1) )%mod ;
}


int dp[2005][2005] ;

int main()
{
    preprocess() ;

    int n , k ;

    scanf("%d %d",&n,&k) ;

    k-- ;

    if(k==0)
    {
        printf("1\n") ;
        return 0 ;
    }

    dp[0][0] = 1 ;

    for(int i=1 ; i<=n ; i++)
    {
        dp[i][0] = (1LL*i*((1LL*dp[i-1][0]*C( i*k - 1 , k-1 ))%mod))%mod ;
     //   dp[i][0] = ( dp[i][0] + dp )

        for(int j=1 ; j<=i ; j++)
        {
            dp[i][j] = (1LL*i*((1LL*dp[i-1][j]*C( i*k + j - 1 , k-1 ))%mod))%mod ;
            dp[i][j] = ( dp[i][j] + dp[i][j-1] )%mod ;
        }
    }

    printf("%d\n",dp[n][n]) ;

    return 0;
}
