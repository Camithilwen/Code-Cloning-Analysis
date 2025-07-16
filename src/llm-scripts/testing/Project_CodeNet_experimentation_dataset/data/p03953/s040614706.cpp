#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,n,m,k,a[200001],d[200001],b[200001],c[200001],nt[200001];
void ksm(){
	ll i;
	while(k){
		if(k&1){
			for(i=1;i<=n;i++)nt[i]=b[c[i]];
			for(i=1;i<=n;i++)b[i]=nt[i];
		}
		for(i=1;i<=n;i++)nt[i]=c[c[i]];
		for(i=1;i<=n;i++)c[i]=nt[i];
		k/=2;
	}
}
int main(){
	ll i,x;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		d[i]=a[i]-a[i-1];
		b[i]=c[i]=i;
	}
	scanf("%lld%lld",&m,&k);
	for(i=1;i<=m;i++){
		scanf("%lld",&x);
		swap(c[x],c[x+1]);
	}
	ksm();
	for(i=1;i<=n;i++){
		ans+=d[b[i]];
		printf("%lld.0\n",ans);
	}
}
/*
思路：对于兔子x[i]，向左跳有2*x[i-1]-x[i]，向右跳有2*x[i+1]-x[i]，概率各位1/2，
得期望x[i-1]+x[i+1]-x[i]，令d[i] = x[i]-x[i-1]，
这条期望式子相当于swap(d[i], d[i+1])，那么连续执行K次，可参考快速幂的做法进行优化。O(NlogK)。
当然也可以O（n）

心得：没有想到用差分 
*/