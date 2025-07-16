#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
	int n;cin>>n;
	ll d;cin>>d;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<ll> r(n);
	r[n-1]=n-1;
	for(int i=n-2;i>=0;i--){
		if(a[r[i+1]]+(r[i+1]-i)*d>a[i]){
			r[i]=i;
		}else{
			r[i]=r[i+1];
		}
	}
	int ri=0;
	ll ra=a[0];
	ll ans=0;
	while(ri!=n-1){
		ans+=ra+a[r[ri+1]]+(r[ri+1]-ri)*d;
		for(int i=ri+1;i<r[ri+1];i++){
			if((i-ri)*d+ra<(r[ri+1]-i)*d+a[r[ri+1]]){
				ans+=a[i]+ra+(i-ri)*d;
			}else{
				ans+=a[i]+(r[ri+1]-i)*d+a[r[ri+1]];
			}
		}
		ra+=(r[ri+1]-ri)*d;
		if(ra>a[r[ri+1]]){
			ra=a[r[ri+1]];
		}
		ri=r[ri+1];
	}
	cout<<ans<<endl;
	return 0;
}

