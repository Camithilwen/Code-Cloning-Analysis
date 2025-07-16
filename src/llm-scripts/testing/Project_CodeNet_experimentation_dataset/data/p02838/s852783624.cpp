#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll cnt[66][2];
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		ll a;cin>>a;
		int bit=0;
		while(a){
			if(a&1){
				cnt[bit][1]++;
			}else cnt[bit][0]++;
			a/=2;
			bit++;
		}
		for(int j=bit;j<=64;j++)cnt[j][0]++;
	}
	ll ans=0;
	for(int i=0;i<=62;i++){
		ll p=(1LL<<i);p%=mod;
		ll hano=cnt[i][0]*cnt[i][1];
		hano%=mod;
		ans+=(p*hano);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}