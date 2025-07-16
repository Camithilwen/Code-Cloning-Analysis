#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const int N=5e6; 
const int INF=0x3f3f3f3f;
int n,m,cnt;
int len=0;
int lin[N]; 
int dis[N];
bool vis[N];
map<pair<int,int>,int> id;
struct edge
{
	int next,y,v;
}e[N];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int Getid(int x,int y)
{
	if(id.find(mp(x,y))!=id.end()) return id[mp(x,y)];
	return id[mp(x,y)]=++cnt;
}
void insert(int xx,int yy,int v)
{
	e[++len].next=lin[xx];
	lin[xx]=len;
	e[len].y=yy;
	e[len].v=v;
}
void add(int xx,int yy,int val)
{
	insert(xx,yy,val),insert(yy,xx,val);
}
void SPFA()
{
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[1]=0,vis[1]=true;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front(); 
		q.pop();
		vis[x]=false;
		for(int i=lin[x];i;i=e[i].next)
		{
			int v=e[i].y;
			if(dis[v]>dis[x]+e[i].v) 
			{
				dis[v]=dis[x]+e[i].v;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
}
int main()
{
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
	n=read(),m=read();
	cnt=n;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),c=read();
		int xx=Getid(u,c);
		int yy=Getid(v,c);
		add(xx,yy,0);
		add(u,xx,1);
		add(v,yy,1);
	}
	SPFA();
	printf("%d",dis[n]!=INF?dis[n]/2:-1);
	return 0;
}
