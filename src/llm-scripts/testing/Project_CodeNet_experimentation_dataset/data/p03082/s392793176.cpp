#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("dichromatic.in","r",stdin)
#define OUT freopen("dichromatic.out","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define INF 1000000000
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define sq(x)  ((x)*(x))

using namespace __gnu_pbds;
using namespace std ;

#define maxn 200005
#define mod 1000000007LL

typedef  long long int T ;

const int N = 100000 ;

int bigMod(int a, int n, int m)
{
    if(n==0 ) return 1 ;
    int r = bigMod(a,n/2,m) ;
    r = (1LL*r*r)%m ;
    if(n&1) r = (1LL*r*a)%m ;
    return r ;
}


int fact[maxn] , invFact[maxn] ;
int dp[maxn] , cnt[maxn] ;
int a[maxn] ;

int C(int n, int r)
{
    return (1LL*fact[n]*((1LL*invFact[r]*invFact[n-r])%mod))%mod ;
}

int main()
{
    fact[0] =1 ;
    for(int i=1 ; i<=2*N ; i++) fact[i] = (1LL*fact[i-1]*i)%mod ;
    invFact[2*N] = bigMod(fact[2*N],mod-2,mod) ;
    for(int i=2*N -1 ; i>=0 ; i--) invFact[i] = (1LL*invFact[i+1]*(i+1))%mod ;

  //  for(int i=0 ; i<=N ; i++) printf("%d\n",invFact[i]) ;

  //  printf("%d %d\n",fact[6],C(6,2)) ;

    int n , X ;
    scanf("%d %d",&n,&X) ;

    for(int i=1; i<=n ; i++) scanf("%d",&a[i]) ;

    sort(a+1,a+n+1) ;

    for(int i=1 ; i<=n ; i++) cnt[ a[i] ]++ ;

    for(int i=1; i<=N ; i++) cnt[i] += cnt[i-1] ;

    dp[0] = 0 ;

    for(int i=1 ; i<=N ; i++)
    {
        if( cnt[i]==0 )
        {
            dp[i] = i ;
            continue ;
        }

        for(int j=cnt[i] ; j>=1 ; j--)
        {
            int m = a[ j ] ;
            int r = i%m ;

            int ret = dp[r] ;
            ret = (1LL*ret*fact[cnt[i]-1])%mod ;
            ret = (1LL*ret*invFact[cnt[r]])%mod;

//            printf("%d----%d %d\n",i,r,ret) ;

            dp[i] = (dp[i]+ret)%mod ;
        }
  //      printf("%d--> %d\n",i,dp[i]) ;
    }

    int ans = (1LL*dp[X]*fact[n])%mod ;
    ans = (1LL*ans*invFact[cnt[X]])%mod ;

    printf("%d\n",ans) ;

    return  0 ;
}
