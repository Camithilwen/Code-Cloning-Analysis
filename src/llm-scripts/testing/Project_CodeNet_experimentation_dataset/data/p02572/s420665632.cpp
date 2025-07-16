#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int main(){
    ll n;
    scanf("%lld",&n);
    ll a[n+1];
    ll sum=0;
    for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);	
		sum=(sum+a[i])%mod;
	} 
	ll ans=0;
	for(int i=1;i<n;i++){
		sum=(sum+mod-a[i])%mod;
		ans=(ans+a[i]*sum)%mod;
	}
	cout<<ans%mod<<endl;
}