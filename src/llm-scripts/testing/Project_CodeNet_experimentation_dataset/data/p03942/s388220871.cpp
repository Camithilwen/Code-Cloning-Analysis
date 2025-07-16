#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
char s[1010101];
char t[1010101];
stack <int> p[26];
int q[1010101],qs=1,qe=0;
int cc[1010101];
int main()
{
	int n,la,now,c=0,ans=0;
	scanf("%d",&n);
	now=n;
	la=n+1;
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)
		p[s[i]-'a'].push(i);
	for(int i=n;i>=1;i--)
	{
		while(now>i)
			now--;
		while(!p[t[i]-'a'].empty()&&p[t[i]-'a'].top()>now)
			p[t[i]-'a'].pop();
		if(p[t[i]-'a'].empty())
		{
			printf("-1");
			return 0;
		}
		now=p[t[i]-'a'].top();
		if(now==la||now==i)
		{
			la=now;
			continue;
		}
		la=now;
		while(qs<=qe&&q[qs]-cc[qs]-c+1>i)
		{
			ans=max(ans,cc[qs]+c);
			qs++;
		}
		c++;
		q[++qe]=now;
		cc[qe]=1-c;
	}
	for(int i=qs;i<=qe;i++)
		ans=max(ans,cc[i]+c);
	printf("%d",ans);
	return 0;
}