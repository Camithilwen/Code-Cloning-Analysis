#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
const ll mod=1e9+7;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
ll n,ans=0,mx=0,a[N],num[100]={0},cnt[100]={0};
void split(ll x){
    ll p=0;
    while(x){
        if(x%2) cnt[p]++;
        p++;
        x/=2;
    }
    mx=max(mx,p);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],split(a[i]);
    for(int i=1;i<=n;i++){
        for(ll j=0;j<mx;j++){
            if(a[i]&(1LL<<j)) num[j]+=n-cnt[j];
            else num[j]+=cnt[j];
        }
    }
    for(ll i=0;i<100;i++){
        num[i+1]+=num[i]/2;
        if(num[i]%2) ans=(ans+power(2,i))%mod;
    }
    cout<<ans*power(2,mod-2)%mod;
    return 0;
}
