#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
const int maxn=4e6+10;
int n,m,head[maxn*2],cnt,vis[maxn*2],dis[maxn*2],tot=200010;
struct edge
{
    int next,to,quan;
} e[maxn*2];
priority_queue<pair<int,int> >q;
map<pair<int,int>,int>mp;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
	if(ch=='-')
	    f=-1;
	ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
	x=(x<<1)+(x<<3)+(ch^48);
	ch=getchar();
    }
    return x*f;
}
inline void add(int from,int to,int quan)
{
    e[++cnt].next=head[from];
    e[cnt].quan=quan;
    e[cnt].to=to;
    head[from]=cnt;
}
int bianhao(int x,int y)
{
    if(mp.find(make_pair(x,y))!=mp.end())
	return mp[make_pair(x,y)];
    return mp[make_pair(x,y)]=++tot;
}
int main()
{
    n=read(),m=read();
    memset(dis,0x3f,sizeof(dis));
    for(int i=1; i<=m; i++)
    {
	int p=read(),q=read(),c=read();
	int t1=bianhao(p,c),t2=bianhao(q,c);
	add(p,t1,1),add(t1,t2,0),add(t2,q,1);
	add(t1,p,1),add(t2,t1,0),add(q,t2,1);
    }
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
	int now=q.top().second;
	q.pop();
	if(vis[now])
	    continue;
	vis[now]=1;
	for(int i=head[now]; i; i=e[i].next)
	{
	    int to=e[i].to;
	    if(dis[to]>dis[now]+e[i].quan)
	    {
		dis[to]=dis[now]+e[i].quan;
		q.push(make_pair(-dis[to],to));
	    }
	}
    }
    if(dis[n]>1e9+10)dis[n]=-2;
    printf("%d",dis[n]/2);
    return 0;
}
