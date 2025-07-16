#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[114514],b[114514];
int main(){
	ll n,inf=1e15;
	cin>>n;
	b[n+1]=inf;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=-inf;
	}
	ll ans=1;
	b[1]=a[1];
	b[0]=inf;
	b[n+1]=-inf;
	for(int i=2;i<=n;i++){
		if(b[ans]>=a[i]){
			ans++;
			b[ans]=a[i];
		}else{
			ll ng=0,ok=n+1;
			while(ok-ng>1){
				ll mid=(ok+ng)/2;
				if(b[mid]>=a[i])ng=mid;
				else ok=mid;
			}
			b[ok]=a[i];
		}
	}
	//for(int i=0;i<=5;i++)cout<<b[i]<<' ';
	cout<<ans;
	return 0;
}
