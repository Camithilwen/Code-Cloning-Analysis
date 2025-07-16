#include <bits/stdc++.h>
const int MOD=1000*1000*1000+7,N=300005;
using namespace std;
typedef long long ll;
ll f[N];
ll h,w,a,b;
ll P(ll a,ll b){
    ll ans=1;
    while(b){
        if(b%2)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return ans;
}
ll WAYS(ll n,ll k){
    ll cnt=f[n];
    cnt=(cnt*P(f[k],MOD-2))%MOD;
    cnt=(cnt*P(f[n-k],MOD-2))%MOD;
    return cnt;
}
int main()
{f[0]=1;
    for(int i=1;i<N;i++)f[i]=(f[i-1]*i)%MOD;
    cin>>h>>w>>a>>b;
    ll ans=0;
    for(int i=b;i<w;i++){
        ll c=h-a;
        ll v1=WAYS(c+i-1,c-1);
        ll v2=WAYS(a+w-i-2,a-1);
        ans=(ans+v1*v2)%MOD;
    }
    cout<<ans<<'\n';
    return 0;
}
