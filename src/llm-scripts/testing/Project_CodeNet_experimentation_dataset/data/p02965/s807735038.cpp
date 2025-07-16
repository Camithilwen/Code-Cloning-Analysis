#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll mod=998244353;
const int SIZE=2010000;
ll fac[SIZE], finv[SIZE], inv[SIZE], sum[260000];
void COMinit(ll m){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2; i<SIZE; ++i){
        fac[i]=(fac[i-1]*i)%m;
        inv[i]=m-(inv[m%i]*(m/i))%m;
        finv[i]=(finv[i-1]*inv[i])%m;
    }
}
ll COM(int n, int k, ll m){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return (fac[n]*((finv[k]*finv[n-k])%m))%m;
}

int main(void){
    int N, M;
    cin >> N >> M;
    COMinit(mod);
    ll ans=0;
    sum[0]=0;
    for(int i=0; i*2<=M; ++i){
        sum[i+1]=(sum[i]+COM(N-2+i, i, mod))%mod;
    }
    for(int i=M%2; i<=min(N, M); i += 2){
        ll num=COM((3*M-i)/2+N-1, N-1, mod);
        (num += mod-(sum[max((3*M-i)/2-M, 0)]*(N-i))%mod) %= mod;
        (num += mod-(sum[max((3*M-i)/2-M+1, 0)]*i)%mod) %= mod;
        (num *= COM(N, i, mod)) %= mod;
        (ans += num) %= mod;
    }
    cout << ans << endl;
    return 0;
}
