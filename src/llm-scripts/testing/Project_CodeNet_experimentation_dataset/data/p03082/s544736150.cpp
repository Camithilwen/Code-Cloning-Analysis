#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
#define MOD 1000000007
using namespace std;



const long max_comb=300;
vector<ll> fac(max_comb+1); //n! (mod M)
vector<ll> ifac(max_comb+1); //k!^(-1) (mod M)

ll mpow(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll minv(ll x){
    return mpow( x, MOD-2 );
}

ll comb(long a, long b){     // C(a,b) = a! * b!^(-1) * (a-b)^(-1)
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

ll perm(long a, long b){     // P(a,b) = a! * (a-b)!^(-1)
    if(b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b] % MOD;
    return tmp * fac[a] % MOD;
}

void pre_comb()
{
    fac[0] = 1;
    ifac[0] = 1;
    for(long i = 0; i<max_comb; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
        ifac[i+1] = ifac[i]*minv(i+1) % MOD; // k!^(-1) (mod M)
    }
    return;
}



ll dp[205][100005];

int main(int argc, char* argv[])
{
    long n, x;
    scanf("%ld%ld", &n, &x);

    vector<long> s(n);
    long i,j;
    for(i=0; i<n; i++) {
        scanf("%ld", &s[i]);
    }
    sort(s.rbegin(), s.rend());

    pre_comb();

    dp[0][x]=1;
    for(i=0; i<n; i++) {
        for(j=0; j<=x; j++) {
            if(dp[i][j]) {
                ll tmp = minv(n-i);
                dp[i+1][j] = (dp[i+1][j] + (dp[i][j]* (1+MOD-tmp)))%MOD;
                dp[i+1][j%s[i]] = (dp[i+1][j%s[i]] + dp[i][j]* tmp)%MOD;
            }
        }
    }

    ll ans=0;
    for(i=0; i<s[n-1]; i++) {
        ans = (ans + i*dp[n][i])%MOD;
    }
    ans = (ans * perm(n,n))%MOD;
    printf("%lld\n", ans);

    return 0;
}
