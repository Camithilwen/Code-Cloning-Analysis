#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	long long num,p;
}a[100010];
int s,n;
long long ans;
bool cmp(node a,node b)
{
	return a.p<b.p;
}
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&a[i].p,&a[i].num);
	sort(a+1,a+n+1,cmp);
	int L=1,R=n;
	int bef=-1;

	while(a[L].p<=s && a[R].p>=s)
	{
		int now;
		if(a[L].num>=a[R].num)
		{
			now=false;
			a[L].num+=a[R].num;
		}
		else
		{
			now=true;
			a[R].num+=a[L].num;
		}
		if(now!=bef)
		{
			ans+=a[R].p-a[L].p;
			bef=now;
		}
		if(a[L].num>=a[R].num) R--;
		else L++;
	}
	if(a[L].p<s) ans+=s-a[L].p;
	else ans+=a[R].p-s;
	printf("%lld",ans);
	return 0;
}