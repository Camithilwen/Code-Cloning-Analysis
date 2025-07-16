#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
	ll n,t,x; cin>>n>>t;
	ll px=-1,ans=0;
	for(ll i=0;i<n;i++){
		cin>>x;
		ans+=t;
		if(px!=-1) ans-=max((ll)0,px-x+t);
		px=x;
	}
	cout<<ans;
}
