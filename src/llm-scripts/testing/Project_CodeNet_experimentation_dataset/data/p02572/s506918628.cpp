#include <bits/stdc++.h>
#define ll unsigned long long 
#define MOD 1000000007
using namespace std;
ll a[2000005];
ll S[2000005];
ll add(ll a,ll b){
	return (a%MOD+b%MOD)%MOD;
}
ll mul(ll a,ll b){
	return (a%MOD*b%MOD)%MOD;
}
int main(){
	int n ;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	S[1] = a[1];
	for(int i=2;i<=n;i++){
		S[i] = add(S[i-1],a[i]);
	}
	ll ans = 0;
	for(int i=1;i<=n-1;i++){
		// 注意大整数取模的时候需要先加上MOd防止暴毙。 
		ans = add(ans,mul(a[i],(S[n]-S[i]+MOD)%MOD))%MOD;
	}
	cout<<ans;
//	
//	ull n,sum = 0;
//    cin >> n;
//    for(int i = 1;i <= n;i++) cin >> arr[i];
//    for(int i = 1;i <= n;i++) ans[i] = (arr[i]+ans[i-1]);
//    for(int i = 1;i <= n;i++) sum = ((sum + arr[i]*((ans[n]-ans[i])%mod))%mod)%mod;
//    cout << sum << endl;
} 