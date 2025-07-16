#include<cstdio>
#include<map>
using namespace std;
int par1[200005],par2[200005];
int rank1[200005],rank2[200005];
typedef pair<int,int> P;
map<P,int>m;
int find(int *par,int x)
{
    if(x==par[x])
        return x;
    else
        return par[x]=find(par,par[x]);
}
void unite(int *par,int *rank,int x,int y)
{
    x=find(par,x);
    y=find(par,y);
    if(x==y)
        return ;
    else
    {
        if(rank[x]>rank[y])
            par[y]=x;
        else
        {
            par[x]=y;
            if(rank[x]==rank[y])
                rank[y]++;
        }
    }
}
int main()
{
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    int p,q;
    for(int i=1;i<=n;i++)
    {
        par1[i]=par2[i]=i;
        rank1[i]=rank2[i]=0;
    }
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&p,&q);
        unite(par1,rank1,p,q);
    }
    for(int i=0;i<l;i++)
    {
        scanf("%d%d",&p,&q);
        unite(par2,rank2,p,q);
    }
    for(int i=1;i<=n;i++)
    {
        find(par1,i);
        find(par2,i);
    }
    for(int i=1;i<=n;i++)
    {
        m[P(par1[i],par2[i])]++;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",m[P(par1[i],par2[i])]);
    }
    return 0;
}
