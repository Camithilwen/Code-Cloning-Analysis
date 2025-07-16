#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[214514];
int main() {
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	ll ans=0;
	if(a[0]!=0)cout<<-1<<endl;
	else{
		ll cnt=1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])cnt++;
			else if(a[i]>a[i-1]){
				if(a[i]-a[i-1]>1){
					cout<<-1<<endl;
					return 0;
				}
				ans+=(cnt-1)*a[i-1];
				cnt=1;
			}else{
				ans+=cnt*a[i-1];
				cnt=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
