#include<cstdio>
#define MAXN 100010
int gcd(int a,int b)
{
	while(b)
	{
		int t=a;a=b;b=t%b;
	}
	return a;
}
int n,a[MAXN];
bool dfs()
{
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++)
		(a[i]&1)?cnt1++:cnt0++;
	if(cnt0&1) return 1;
	if(cnt1>1) return 0;
	for(int i=1;i<=n;i++)
		if(a[i]&1)
		{
			if(a[i]==1) return 0;
			a[i]--;
			break;
		}
	int d=a[1];
	for(int i=2;i<=n;i++)
		d=gcd(a[i],d);
	for(int i=1;i<=n;i++)
		a[i]/=d;
	return !dfs();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(dfs()) printf("First\n");
	else printf("Second\n");
}
