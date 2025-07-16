#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
typedef long long ll;
ll a[N],n,m,v,p;
int ans;
bool cmp(ll x,ll y) {
	return x>y;
}
int main() {
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	ll d=a[p];
	ans=p;
	for(ll i=p+1;i<=n;i++) {
		if(a[i]+m>=a[p]) {
			ll cnt=max(0ll,v-(n-i+p)); //p~i-1 放的点数 
			if(cnt==0) ans++;
			else {
				if(d+cnt*m<=(a[i]+m)*(i-p))
					ans++;
				else break;
			}
		}
		else break;
		d+=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
