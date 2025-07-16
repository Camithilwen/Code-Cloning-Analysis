#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const long long MAXN=1000005;

int n,m;
char S[MAXN],T[MAXN];
stack<int> s[30];
pair<int,int> que[MAXN];
int hd,tl;

int main()
{
    scanf("%d%s%s",&n,S+1,T+1);
	for(int i=1;i<=n;i++)
		s[S[i]-'a'].push(i);
	hd=1;tl=0;
	int now=n,last=n+1,c=0;
	int ans=0;
    for(int i=n;i>=1;i--)
	{
		now=min(now,i);
		while(!s[T[i]-'a'].empty()&&s[T[i]-'a'].top()>now)
			s[T[i]-'a'].pop();
		if(s[T[i]-'a'].empty())
		{
			puts("-1");
			return 0;
		}
		now=s[T[i]-'a'].top();
		if(now==i||now==last)
		{
			last=now;
			continue;
		}
		last=now;
		while(hd<=tl&&que[hd].first-que[hd].second-c+1>i)
		{
			ans=max(ans,que[hd].second+c);
			hd++;
		}
		c++;
		que[++tl]=make_pair(now,1-c);
	}
	for(int i=hd;i<=tl;i++)
		ans=max(ans,que[i].second+c);
	printf("%d\n",ans);

    return 0;
}
