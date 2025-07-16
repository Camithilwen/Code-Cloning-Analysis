#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x[100005],y[100005],mod=1e9+7;
ll calc(ll a[],ll n){
    ll ans =0 ;
    for(ll i=0;i<n-1;i++)a[i]=a[i+1]-a[i];
    n-=1;
    for(ll i=0;i<n;i++){
        ans = ans  + (i+1)*(n-i)%mod*a[i]%mod;
        ans%=mod;
    }
    return ans;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(ll i=0;i<n;i++)cin>>x[i];
    for(ll i=0;i<m;i++)cin>>y[i];
    cout<< (calc(x,n) * calc(y,m) )%mod;
}