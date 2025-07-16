#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define ii pair<int,int>
#define mod 1000000007
#define endl '\n'
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans;
}

void sieve(int n){
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for(int p=2;p<=n;p++){
		if(prime[p])
			cout<<p<<" ";
	}
}

int ans(int index,int time,int t,vector<pair<int,int>>& v,vector<vector<int>>& value){
	if(index>=v.size())
		return 0;
	if(time>=t)
		return 0;
	if(value[index][time]!=-1)
		return value[index][time];
	int returnVal=0;
	returnVal = v[index].second + ans(index+1,time+v[index].first,t,v,value);
	returnVal = max(returnVal,ans(index+1,time,t,v,value));
	value[index][time]=returnVal;
	return returnVal;
}

int main() {
	IOS;
	int n,t;
	cin>>n>>t;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		int p,q;
		cin>>p>>q;
		v.push_back({p,q});
	}
	sort(v.begin(),v.end());
	std::vector<vector<int>> va(n+1,vector<int> (t+1,-1));
	cout<<ans(0,0,t,v,va);

	return 0;
}