#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+100;
const int M=4e5+100;
int head1[N],ver1[M],Next1[M];
int tot1,tot2;
int add1(int x,int y)
{
	ver1[++tot1]=y;
	Next1[tot1]=head1[x];
	head1[x]=tot1;
}

int head2[N],ver2[M],Next2[M];
int add2(int x,int y)
{
	ver2[++tot2]=y;
	Next2[tot2]=head2[x];
	head2[x]=tot2;
}
int cnt=0;
int c1[N],c2[N];
void dfs1(int x)
{
	c1[x]=cnt;
	for(int i=head1[x];i;i=Next1[i])
	{
		int y=ver1[i];
		if(c1[y])continue;
		dfs1(y);
	}
}
void dfs2(int x)
{
	
	c2[x]=cnt;
	for(int i=head2[x];i;i=Next2[i])
	{
		int y=ver2[i];
		
		if(c2[y])continue;
		dfs2(y);
	}
}

map<pair<int,int>,int>MM;
int main()
{
	int n,k,l;
	while(cin>>n>>k>>l)
	{
		MM.clear();
		memset(head1,0,sizeof(head1));
		memset(ver1,0,sizeof(ver1));
		memset(Next1,0,sizeof(Next1));
		memset(head2,0,sizeof(head2));
		memset(ver2,0,sizeof(ver2));
		memset(Next2,0,sizeof(Next2));
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		tot1=0;
		tot2=0;
		for(int i=1;i<=k;i++)
		{
			int x,y;
			cin>>x>>y;
			add1(x,y);
			add1(y,x);
		}
		
		for(int i=1;i<=l;i++)
		{
			int x,y;
			cin>>x>>y;
			add2(x,y);
			add2(y,x);
		}
		for(int i=1;i<=n;i++)
		{
			if(c1[i]==0)
			{
				cnt++;
				dfs1(i);
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c2[i]==0)
			{
				cnt++;
				dfs2(i);
			}
		}
		
		for(int i=1;i<=n;i++)
			MM[make_pair(c1[i],c2[i])]++;
		for(int i=1;i<=n;i++)
		{
			cout<<MM[make_pair(c1[i],c2[i])]<<" ";
			if(i==n)cout<<endl;
		}
		
	}
	return 0;
} 