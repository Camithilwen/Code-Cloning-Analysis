#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
#define MAX(x,y) x=max(x,y)
using namespace std;
 
const int N=18;
const int M=32775;
 
int n,m,bin[N],num[M],ma[N][M],sum[M],f[N][M],g[M];
 
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
 
int lowbit(int x)
{
	return x&(-x);
}
 
int main()
{
	n=read();m=read();
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2,num[bin[i]]=i;
	int tot=0;
	for (int i=1;i<=m;i++)
	{
		int x=read()-1,y=read()-1,z=read();tot+=z;
		ma[x][bin[y]]=ma[y][bin[x]]=z;
	}
	for (int i=0;i<n;i++)
		for (int j=1;j<bin[n];j++)
			ma[i][j]=ma[i][j-lowbit(j)]+ma[i][lowbit(j)];
	for (int i=1;i<bin[n];i++) sum[i]=sum[i-lowbit(i)]+ma[num[lowbit(i)]][i-lowbit(i)];
	for (int i=0;i<n;i++)
		for (int j=0;j<bin[n];j++)
			f[i][j]=-inf;
	f[0][1]=0;
	for (int j=0;j<bin[n];j++)
		for (int i=0;i<n-1;i++)
		{
			if (f[i][j]<0) continue;
			for (int k=0;k<n;k++)
				if (!(j&bin[k])&&ma[i][bin[k]]) MAX(f[k][j+bin[k]],f[i][j]+ma[i][bin[k]]);
		}
	for (int i=0;i<bin[n];i++) g[i]=f[n-1][i];
	for (int i=1;i<bin[n];i++)
	{
		if (g[i]<0) continue;
		int r=i^(bin[n]-1);
		for (int s=r;s;s=(s-1)&r)
		{
			int mxv=0;
			for (int j=i;j;j-=lowbit(j)) mxv=max(mxv,sum[s+lowbit(j)]);
			MAX(g[i+s],g[i]+mxv);
		}
	}
	printf("%d",tot-g[bin[n]-1]);
	return 0;
}