#include<bits/stdc++.h>
using namespace std;
int n;
char s[1000100];
char t[1000100];
queue<int>q;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int ans=0;
	for(int i=1;i<=n;++i)
		if(s[i]!=t[i]){ans=1;break;}
	if(!ans)
	{
		puts("0");
		return 0;
	}
	for(int up=n,dn=n;dn;--dn)
	{
		while(t[dn-1]==t[dn])dn--;
		up=min(up,dn);
		while(s[up]!=t[dn]&&up)up--;
		if(!up)
		{
			puts("-1");
			return 0;
		}
		while(!q.empty())
		{
			if(q.front()-q.size()+1>dn)q.pop();
			else break;
		}
		if(up!=dn)q.push(up);
		ans=max(ans,(int)q.size()+1);
	}
	printf("%d\n",ans);
	return 0;
}
