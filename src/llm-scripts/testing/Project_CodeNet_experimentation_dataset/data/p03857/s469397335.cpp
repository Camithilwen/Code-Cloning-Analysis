#include<map>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mp make_pair
using namespace std;

map<pair<int,int>,int> m;

struct dsu
{
    int fa[200010],rank[200010];
    
    void init(int n)
    {
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
    }
    
    int find(int x)
    {
        if(fa[x]==x)
        {
            return x;
        }
        return fa[x]=find(fa[x]);
    }
    
    void union_(int x,int y)
    {
        int fx=find(x);
        int fy=find(y);
        if(fx==fy)
        {
            return ;
        }
        if(rank[fx]<rank[fy])
        {
            fa[fx]=fy;
        }
        else
        {
            fa[fy]=fx;
            if(rank[fx]==rank[fy])
            {
                rank[x]++;
            }
        }
    }
    
    int same(int x,int y)
    {
        return find(x)==find(y);
    }
}a,b;

int main()
{
    //give the fucking vjudge a flying fucking
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    a.init(n);
    b.init(n);
    int from,to;
    for(int i=1;i<=x;i++)
    {
        scanf("%d%d",&from,&to);
        a.union_(from,to);
    }
    for(int i=1;i<=y;i++)
    {
        scanf("%d%d",&from,&to);
        b.union_(from,to);
    }
    for(int i=1;i<=n;i++)
    {
        m[mp(a.find(i),b.find(i))]++;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",m[mp(a.find(i),b.find(i))]);
    }
}