#include<iostream>
#include<cstdio>
using namespace std;
#define N 200012
int n,a[N],las=0;bool vis[N];long long ans=0;
int main(){
	scanf("%d",&n);int i,l,r,lef;bool fl=true;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i=r+1)
	{
		l=r=i;while((r<n)&&(a[r+1]==(a[r]+1)))++r;
		lef=l-a[l];if(lef<=las){printf("-1");fl=false;break;}
		ans+=r-lef;las=lef;
	}if(fl)printf("%lld",ans);return 0;
}