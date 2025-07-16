#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fr first
#define sc second
#define pb push_back
const ll mod = 1e9+7;
const int N = 2e5+205;
void solve(){
	int n; 
	cin>>n;
	vector<ll>v; 
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		v.pb(x);
	}
	sort(v.begin(),v.end());
	ll ans = 0;
	for(int i=0;i+1<n;i+=2){
		if(v[i]+v[i+1]>-v[i]-v[i+1]){
			ans+=v[i]+v[i+1];
		}
		else{
			ans+=(-v[i]-v[i+1]);
		}
	}
	if(n&1)ans+=v[n-1];
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
/// 2:3 /// 2,3
/// 1:1 /// 3,3
/// aa/bb =x/y
/// bb*x/y = aa
/// bb = aa*y/x
