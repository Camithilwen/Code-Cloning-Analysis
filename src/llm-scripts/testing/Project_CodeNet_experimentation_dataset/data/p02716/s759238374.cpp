#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e17;
const int N=2e5+10;
int a[N];
ll f[N],c1[N],c2[N];
int n;
int main() {
	ll ans,cnt;
	int i;
	ans=-INF;
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (i==1) c2[i]=a[i];
		else if (i%2==0) c1[i]=c1[i-2]+a[i];
		else c2[i]=c2[i-2]+a[i];
	}
	for (i=2;i<=n;i++) {
		if (i%2==0) f[i]=max(f[i-2]+a[i],c2[i-1]);
		else f[i]=max(f[i-2]+a[i],f[i-1]);
//		cout<<i<<' '<<f[i]<<endl;
	}
	printf("%lld\n",f[n]);
	return 0;
}