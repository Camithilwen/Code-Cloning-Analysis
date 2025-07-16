#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF (2e9)
const int maxv=10000+10;
const int maxe=100000+10;
int V,E;
int d[maxv];
struct Edge
{
    int from,to,cost;
};
Edge es[maxe];

int p[maxv];
int rank[maxv];

bool cmp(const Edge& a,const Edge& b)
{
    return a.cost<b.cost;
}


void init(int n)
{
    for(int i=0; i<n; i++)
    {
        p[i]=i;
        rank[i]=0;
    }
}
int fnd(int x)
{
    if(x==p[x]) return x;
    return fnd(p[x]);

}
bool is_same(int x,int y)
{
    return fnd(x)==fnd(y);

}
void unite(int x,int y)
{
    x=fnd(x);
    y=fnd(y);
    if(x==y) return;
    if(rank[x]>rank[y])
    {
        p[y]=x;
    }
    else
    {
        p[x]=y;
        if(rank[x]==rank[y]) rank[y]++;
    }
}
void kruskal()
{
    sort(es,es+E,cmp);
    init(V);
    int res=0;
    for(int i=0; i<E; i++)
    {
        Edge &e=es[i];
        if(!is_same(e.from,e.to))
        {
            unite(e.from,e.to);
            res+=e.cost;
        }
    }
    printf("%d\n",res);
}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&V,&E);
    int u,v,cost;
    for(int i=0; i<E; i++)
    {
        scanf("%d%d%d",&u,&v,&cost);
        es[i].from=u;
        es[i].to=v;
        es[i].cost=cost;
    }
    kruskal();
    return 0;
}