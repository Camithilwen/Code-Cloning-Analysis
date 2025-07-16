#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	bool ok=(a[0]==0);
	rep(i,n-1) if(a[i+1]-a[i]>=2) ok=false;
	if(!ok){
		puts("-1");
		return 0;
	}

	lint ans=0;
	int pre=0;
	for(int i=1;i<=n;i++){
		if(i==n || a[i-1]+1!=a[i]){
			ans+=a[i-1];
			pre=i;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
