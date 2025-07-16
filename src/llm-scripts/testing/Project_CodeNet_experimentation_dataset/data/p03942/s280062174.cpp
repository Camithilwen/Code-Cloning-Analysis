#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[MN+5],t[MN+5];
int last[MN+5][26],a[MN+5],n,ans=0;
int main()
{
	n=read();
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;++i) 
	{
		memcpy(last[i],last[i-1],sizeof(last[0]));
		last[i][s[i]-'a']=i;
	}
	for(int i=n,j=n,r=0,k=0;i;--i)
	{
		if(j>i) j=i;
		if(s[j]!=t[i])
		{
			if(!last[j][t[i]-'a']) return 0*puts("-1");
			j=last[j][t[i]-'a'];
			++r;++k;ans=max(ans,k);
			++a[j+r];
		}
		k-=a[i+r];a[i+r]=0;
	}
	cout<<ans;
	return 0;
}

