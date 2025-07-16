#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}

	inline int ts(char *s)
	{
		int a=0,c=fetch();
		while(c<=32 && c!=EOF)c=fetch();
		while(c>32 && c!=EOF)s[a++]=c,c=fetch();
		s[a]=0;
		return a;
	}
}
using ae86::ty;
using ae86::ts;

const int _ = 1000007;

int n,que[_],he,ta;char s[_]={0},t[_]={0};

int main()
{
	n=ty(),ts(s+1),ts(t+1);

	int got=0;
	for(int i=1;i<=n;i++)if(s[i]!=t[i]){got=1;break;}
	if(!got){puts("0");return 0;}
	
	he=1,ta=0;
	int ans=0;
	for(int i=n,j=n;i>=1;i--)
	{
		if(t[i]==t[i-1])continue;
		j=min(j,i);
		while(j>0 && s[j]!=t[i])j--;
		if(j<=0){puts("-1");return 0;}
		while(he<=ta && que[he]-(ta-he+1)+1>i)he++;
		que[++ta]=j;
		if(i!=j)ans=max(ans,ta-he+1);
	}
	printf("%d\n",ans+1);

	return 0;
}
