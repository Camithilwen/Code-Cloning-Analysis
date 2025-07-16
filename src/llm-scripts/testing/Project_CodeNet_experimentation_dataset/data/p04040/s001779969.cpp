#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
const LL mof=1e9+7;
LL p=mof;
const LL maxn=200007;
inline LL pow_mod(LL a,LL k,LL mo)
{
    LL ans=1;
    while(k)
    {
        if(k%2) ans=ans*a%mo;
        a=a*a%mo;
        k>>=1;
    }
    return ans%mo;
}
LL jc[maxn+7];
inline LL inv(LL x)
{
    return pow_mod(x,mof-2,mof);
}
LL Inv[maxn+7];
LL C(LL N,LL k)
{
    if(k>N||k<0)return 0;
    if(k==0||k==N)return 1;
    LL ans=1;
    ans=ans*jc[N]*Inv[k]%mof*Inv[N-k]%mof;
    return ans;
}
void init()
{
    jc[1]=jc[0]=1;
    for(LL i=2; i<=maxn; ++i) jc[i]=jc[i-1]*i%mof;
    for(int i=0; i<=maxn; ++i) Inv[i]=inv(jc[i]);
}
const long long MOD = 1000000007;

void solve(long long H, long long W, long long A, long long B){
    LL ans = 0;
    LL h = H-A;
    for(LL w=B+1;w<=W;++w)
    {
        ans += C(h+w-2,h-1) * C(H-h+W-w-1,H-h-1);
        ans %= mof;
    }
    cout<<ans<<endl;
}

int main(){
    init();
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(H, W, A, B);
    return 0;
}
