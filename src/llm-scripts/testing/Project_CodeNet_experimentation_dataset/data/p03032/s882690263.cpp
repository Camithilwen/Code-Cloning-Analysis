#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[110];
int main(){
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=0;i<=min(n,k);i++)for(int j=0;j<=min(n,k)-i;j++){
		vector<ll>v;
		ll sum=0;
		for(int l=1;l<=n;l++){
			if((1<=l&&l<=i)||(n+1-j<=l&&l<=n)){
				sum+=a[l];
				v.push_back(a[l]);
			}
		}
		ll num=k-i-j;
		//cout<<sum<<' '<<v.size()<<endl;
		sort(v.begin(),v.end());
		for(int l=0;l<min(num,(long long)v.size());l++){
			if(v[l]>=0)break;
			sum-=v[l];
		}
		//cout<<num<<' '<<sum<<endl;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
