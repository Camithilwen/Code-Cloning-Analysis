#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll D,ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>D;
	if(D%9){
		cout<<0<<'\n';
		return 0;
	}
	D/=9;ll pw=1;
	for(int i=1;i<=17;++i){
		ll tmp=1,d=D,lp=pw,rp=1;pw*=10;
		ll b=(pw-1)/9;
		for(int j=0;j+j<=i;++j){
			tmp*=10-abs(d%(rp*10)/rp)-!j;
			d-=b*(d%(rp*10)/rp);
			b-=lp+rp;lp/=10;rp*=10;
		}
		if(!d)ans+=tmp;
	}
	cout<<ans<<'\n';
	return 0;
}
