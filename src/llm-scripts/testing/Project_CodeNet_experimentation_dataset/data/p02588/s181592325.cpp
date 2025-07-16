#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
int bit[55][55];
void add(int x, int y){
	for(int i=x;i>0;i-=(i&-i)){
		for(int j=y;j>0;j-=(j&-j)){
			bit[i][j]++;
		}
	}
}
ll get(int x, int y){
	ll ret =0;
	for(int i=x;i<55;i+=(i&-i)){
		for(int j=y;j<55;j+=(j&-j)){
			ret+=bit[i][j];
		}
	}
	return ret;
}
ll get2(ll x){
	ll ret = 1;
	while(x%2==0){
		ret++;
		x/=2;
	}
	return ret;
}
ll get5(ll x){
	ll ret = 1;
	while(x%5==0){
		ret++;
		x/=5;
	}
	return ret;
}
void solve(){
	int n; 
	cin>>n;
	ll ans = 0; 
	for(int i=1;i<=n;i++){
		ld inp; 
		cin>>inp; 
		ll trt = llround(inp*1e9);
		ll x = get2(trt);
		ll y = get5(trt);
		ll xp = max(1ll,20-x);
		ll yp = max(1ll,20-y);
		ans+=get(xp,yp);
		add(x,y);
	}
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
