#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,S;
ll a[N],p[N],tag[N];
ll ans;
int main(){
	cin>>n>>S;
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&p[i]);
	int l=1,r=n;
	while (a[l]<=S&&S<=a[r]){
		if (p[l]>=p[r]){
			if (!tag[l])ans+=a[r]-a[l],tag[l]=1;
			p[l]+=p[r];
			r--;
		}
		else {
			if (!tag[r])ans+=a[r]-a[l],tag[r]=1;
			p[r]+=p[l];
			l++;
		}
	}
	ans+=max(abs(S-a[l]),abs(S-a[r]));
	cout<<ans<<endl;
}