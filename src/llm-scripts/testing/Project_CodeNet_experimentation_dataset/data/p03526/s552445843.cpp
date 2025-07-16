#include"bits/stdc++.h"
using namespace std;
const int N=5e3+100;
typedef long long LL;
struct node{
	LL h,p;
}a[N];
LL dp[N];
bool cmp(node a,node b){
	if(a.h+a.p==b.h+b.p)return a.h<b.h;
	return a.h+a.p<b.h+b.p;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<=5050;i++)dp[i]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)
		scanf("%d %d",&a[i].h,&a[i].p);
	sort(a+1,a+n+1,cmp);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if(a[i].h>=dp[j]){
				dp[j+1]=min(dp[j+1],dp[j]+a[i].p);
			}
		}
	}
	int ans=1;
	for(int i=2;i<=n;i++)
		if(dp[i]!=0x3f3f3f3f3f3f3f3f)ans=i;
	printf("%d\n",ans);
}