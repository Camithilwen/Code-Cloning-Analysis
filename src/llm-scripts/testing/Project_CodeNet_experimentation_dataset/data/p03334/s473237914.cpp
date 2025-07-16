#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
int sq[555555],d1,d2,xx,yy,p[555555],cnt,n,col[555555],msk[555555],pos,sum[5],id;
int cnt1,cnt2,cpt,pa[555555],val[555555];
pair<int,int> v1[1111],v2[1111];
int root(int x)
{
	if (pa[x]==x) return x;
	int rt=root(pa[x]);
	val[x]^=val[pa[x]];
	return pa[x]=rt;
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;val[rx]=(1^val[x]^val[y]);
}
void Init()
{
	memset(sq,-1,sizeof(sq));
	for (int i=0;i<=500;i++) sq[i*i]=i;
}
int get(int x,int y)
{
	return (x-1)*n+y;
}
bool In(int x,int y)
{
	return (x>=1 && x<=n && y>=1 && y<=n);
}
void addedge(int x,int y)
{
	Union(x,y);
}
int main()
{
	scanf("%d%d%d",&n,&d1,&d2);
	Init();n<<=1;
	for (int k=0;k<=n;k++)
	{
		if (d1-k*k>=0 && ~sq[d1-k*k]) 
		{
			v1[++cnt1]=make_pair(k,sq[d1-k*k]);
		}
		if (d2-k*k>=0 && ~sq[d2-k*k]) 
		{
			v2[++cnt2]=make_pair(k,sq[d2-k*k]);
		}
	}
	for (int i=1;i<=n*n;i++)
	{
		pa[i]=i;
		val[i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			id=get(i,j);
			for (int k=1;k<=cnt1;k++)
			{
				xx=i+v1[k].first;yy=j+v1[k].second;
				if (In(xx,yy)) addedge(id,get(xx,yy));
				xx=i-v1[k].first;yy=j+v1[k].second;
				if (In(xx,yy)) addedge(id,get(xx,yy));
			}
		}
	}
	for (int i=1;i<=n*n;i++)
	{
		root(i);
		col[i]=val[i];
	}
	for (int i=1;i<=n*n;i++) msk[i]=col[i];
	for (int i=1;i<=n*n;i++)
	{
		pa[i]=i;
		val[i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			id=get(i,j);
			for (int k=1;k<=cnt2;k++)
			{
				xx=i+v2[k].first;yy=j+v2[k].second;
				if (In(xx,yy)) addedge(id,get(xx,yy));
				xx=i-v2[k].first;yy=j+v2[k].second;
				if (In(xx,yy)) addedge(id,get(xx,yy));
			}
		}
	}
	for (int i=1;i<=n*n;i++)
	{
		root(i);
		col[i]=val[i];
	}
	for (int i=1;i<=n*n;i++) msk[i]|=(col[i]<<1);
	for (int i=1;i<=n*n;i++) sum[msk[i]]++;
	for (int i=0;i<4;i++)
	{
		if (sum[i]>=n*n/4) 
		{
			pos=i;
			break;
		}
	}
	for (int i=1;i<=n*n;i++)
	{
		if (cnt==n*n/4) break;
		if (msk[i]==pos) 
		{
			printf("%d %d\n",(i-1)/n,(i-1)%n);
			cnt++;
		}
	}
	return 0;
}