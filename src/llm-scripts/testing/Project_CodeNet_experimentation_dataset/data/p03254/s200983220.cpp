#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
ll a[123];
void solve(){
	int n;
	ll x; 
	cin>>n>>x; 
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll sum = 0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(sum+a[i]<=x){
			ans = i;
		}
		sum+=a[i];
	}
	if(sum<x)ans = n-1;
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
