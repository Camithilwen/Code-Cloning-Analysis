#include<cstdio>
#include<algorithm>
typedef long long lint;
lint doz[23];
lint D;

lint dfs(int l,int r,lint d)
{
	if(l>=r)
	{
		if(d) return 0;
		return l==r?10ll:1ll;
	}
	if(d%10==0)
	{
		if(l==1) return dfs(l+1,r-1,d/10)*9;
		return dfs(l+1,r-1,d/10)*10;
	}
	lint di=d%10-10;
	lint de=d+di*(doz[r-l]-1ll);
	if(l==1) return dfs(l+1,r-1,(de>0?de:-de)/10)*(di+9);
	return dfs(l+1,r-1,(de>0?de:-de)/10)*(di+10);
}

int main()
{
	scanf("%lld",&D);
	doz[0]=1;for(int i=1;i<=18;i++) doz[i]=doz[i-1]*10ll;
	lint ans=0;
	for(int i=2;i<=18;i++) ans+=dfs(1,i,D);
	printf("%lld\n",ans);
	return 0;
}
