#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
const int INF=10000000;
int p1[N],p2[N];
map<pair<int,int>,int>m;
int find(int x,int *p)
{
    return p[x]==x?p[x]:p[x]=find(p[x],p);
}
void cha(int x,int y,int *p)
{
    int px=find(x,p);
    int py=find(y,p);
    if(px!=py)
    {
        p[px]=py;
    }
}
int main()
{
    int n,k,l;
    cin>>n>>k>>l;
    for(int i=1;i<=n;i++)
        p1[i]=i,p2[i]=i;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d%d,",&x,&y);
        cha(x,y,p1);
    }
    for(int i=1;i<=l;i++)
    {
        int x,y;
        scanf("%d%d,",&x,&y);
        cha(x,y,p2);
    }
    for(int i=1;i<=n;i++)
    {
        find(i,p1);
        find(i,p2);
    }
    for(int i=1;i<=n;i++)
        m[make_pair(p1[i],p2[i])]++;
    for(int i=1;i<=n;i++)
        printf("%d ",m[make_pair(p1[i],p2[i])]);
    return 0;
}