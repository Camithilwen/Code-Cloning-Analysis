#include<cstdio>
const int N=1000005;
int n,he[128],nx[N],a,qu[N*2],hd,tl,d;char s[N],t[N];
inline int mx(int x,int y){return x>y?x:y;}
int main()
{
	scanf("%d%s%s",&n,s+1,t+1),hd=n+1,tl=n;
	for(int i=1;i<=n;++i)nx[i]=he[s[i]],he[s[i]]=i;
	for(int i=n;i;--i)
	{
		if(hd>tl||i<qu[hd]-d)
		{
			hd=n+1,tl=n,d=0;
			if(s[i]!=t[i])
			{
				for(;he[t[i]]&&he[t[i]]>=i;he[t[i]]=nx[he[t[i]]]);
				if(!he[t[i]])return printf("-1"),0;
				qu[--hd]=he[t[i]],qu[++tl]=i;
			}
		}
		else
		{
			if(s[qu[hd]-d]!=t[i])
			{
				for(;he[t[i]]&&he[t[i]]>=qu[hd]-d;he[t[i]]=nx[he[t[i]]]);
				if(!he[t[i]])return printf("-1"),0;
				for(;qu[tl]-d>i;--tl);++d,qu[--hd]=he[t[i]]+d,qu[++tl]=i+d;
			}
		}
		a=mx(a,tl-hd);
	}
	printf("%d",a);
	return 0;
}