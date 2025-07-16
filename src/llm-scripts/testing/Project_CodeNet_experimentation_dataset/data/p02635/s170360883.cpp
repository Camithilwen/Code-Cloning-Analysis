#include<bits/stdc++.h>

#define ll long long
#define rep(A,B,C) for(A=B;A<C;++A)
#define repd(A,B,C) for(A=(ll)C-1;A>=B;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>
void mxin(T& a,T b){if(a<b)a = b;}
template<typename T>
void mnin(T& a,T b){if(a>b)a = b;}
using namespace std;

/////////////////////////////////////////////////////
#define MOD 998244353
#define MXN 333

char S[333];
ll N,K;
ll dp[MXN][MXN], odp[MXN][MXN];
ll i, j, k, l;

int main(){
    scanf("%s%lld", S, &K);
    N = strlen(S);
    K = min(N, K);

    dp[0][0] = 1;
    ll pi = N;
    for (i = N - 1; i >= 0;--i)
    {
        if(S[i]=='1')
            continue;
        rep(j,0,MXN){
            rep(k,0,MXN){
                odp[j][k] = dp[j][k];
                dp[j][k] = 0;
            }
        }
        ll a = pi - i;
        pi = i;
        rep(j,0,K+1){
            ll b = 0;
            for(k = j; k >= 0;--k){
                (b += odp[j][k]) %= MOD;
                (dp[j][k] += b) %= MOD;
                if(odp[j][k]==0)
                    continue;
                rep(l,1,a){
                    (dp[j + l][k + l] += odp[j][k]) %= MOD;
                }
            }
        }
        //printf("\n%lld:\n", i);
        /*
        rep(j,0,N+1){
            rep(k,0,j+1){
                printf("%lld ", dp[j][k]);
            }
            printf("\n");
        }*/
    }
    ll ans = 0;
    rep(i,0,K+1){
        rep(j,0,i+1){
            (ans += dp[i][j]) %= MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}