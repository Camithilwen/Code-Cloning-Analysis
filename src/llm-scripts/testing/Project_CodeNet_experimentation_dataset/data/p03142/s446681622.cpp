#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
#define N 300010
#define ll long long
int n,m,p[N],fa[N],deep[N],degree[N],q[N],t,root;
bool flag[N];
struct data{int to,nxt;
}edge[N];
void addedge(int x,int y){t++;edge[t].to=y,edge[t].nxt=p[x],p[x]=t;}
void topsort()
{
	int head=0,tail=0;
	for (int i=1;i<=n;i++) if (!degree[i]) q[++tail]=i;
	while (tail<n)
	{
		int x=q[++head];
		for (int i=p[x];i;i=edge[i].nxt)
		{
			degree[edge[i].to]--;
			if (deep[x]+1>deep[edge[i].to])
			{
				deep[edge[i].to]=deep[x]+1;
				fa[edge[i].to]=x;
			}
			if (!degree[edge[i].to]) q[++tail]=edge[i].to;
		}
	}
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<n+m;i++)
	{
		int x=read(),y=read();
		addedge(x,y);degree[y]++;
	}
	topsort();
	for (int i=1;i<=n;i++) printf("%d\n",fa[i]);
	return 0;
}