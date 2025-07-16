#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll bi[514514];
void add(ll n,ll i,ll x){
	for(;i<=n;i+=i&-i)bi[i]+=x;
}
ll sum(ll i){
	ll num=0;
	for(;i>0;i-=i&-i)num+=bi[i];
	return num;
}
ll c[514514],g[514514],ans[514514];
int main(){
	ll n,q;
	cin>>n>>q;
	vector<vector<ll>>v(n+1),w(n+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<q;i++){
		ll l,r;
		cin>>l>>r;
		v[r].push_back(l);
		w[r].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(g[c[i]])add(n,g[c[i]],-1);
		add(n,i,1);
		g[c[i]]=i;
		ll cnt=0;
		for(ll p:v[i]){
			ans[w[i][cnt]]=sum(i)-sum(p-1);
			cnt++;
		}
	}
	for(int i=0;i<q;i++)cout<<ans[i]<<endl;
	return 0;
}
