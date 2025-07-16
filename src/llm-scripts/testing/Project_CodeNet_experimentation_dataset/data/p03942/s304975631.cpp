#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
#define N 1100005
struct node
{
	int st,ed,cnt;
	char c;
}a[N];
int c[N];
int n,z;
char ch[N],cc[N];
queue<int>q;
int main()
{
	//freopen("copy.in","r",stdin);
	//freopen("copy.out","w",stdout);
	scanf("%d%s%s",&n,ch+1,cc+1);
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(ch[i]!=cc[i])
		{
			flag=false;
			break;
		}
	}
	if(ch[1]!=cc[1])
	{
		puts("-1");return 0;
	}
	if(flag)
	{
		puts("0");return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<=n&&cc[j]==cc[i])j++;
		a[++z].st=i;a[z].ed=j;
		if(cc[j]!=cc[i])a[z].ed--;
		a[z].c=cc[i];
		i=a[z].ed;
	}
	int la=n,ans=0;
	for(int i=z;i;i--)
	{
		la=min(la,a[i].st);
		while(la&&a[i].c!=ch[la])la--;
		if(la==0)
		{
			puts("-1");return 0;
		}
		while(!q.empty()&&q.front()-q.size()>=a[i].ed)q.pop();
		q.push(la);
		int te=q.size();
		ans=max(ans,te);
	}
	printf("%d\n",ans);
}