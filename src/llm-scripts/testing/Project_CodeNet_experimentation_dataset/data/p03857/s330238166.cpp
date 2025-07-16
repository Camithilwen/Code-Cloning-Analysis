#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define maxn 200005
using namespace std;
int n,k,l;
int father1[maxn];
int father2[maxn];
map<pair<int,int>,int>mp;
int find1(int x)
{
    if(father1[x]!=x)
       father1[x]=find1(father1[x]);
    return father1[x];
}
int find2(int x)
{
    if(father2[x]!=x)
        father2[x]=find2(father2[x]);
    return father2[x];
}
void unionn1(int x,int y)
{
    int fa=find1(x);
    int fb=find1(y);
    if(fa!=fb)
        father1[fa]=fb;
}
void unionn2(int x,int y)
{
    int fa=find2(x);
    int fb=find2(y);
    if(fa!=fb)
        father2[fa]=fb;
}
int main()
{scanf("%d%d%d",&n,&k,&l);
for(int i=0;i<=n;i++)
    {father1[i]=i;
    father2[i]=i;
    }
int p,q;
for(int i=1;i<=k;i++)
{scanf("%d%d",&p,&q);
    unionn1(p,q);
}
int r,s;
for(int i=1;i<=l;i++)
{scanf("%d%d",&r,&s);
unionn2(r,s);
}
for(int i=1;i<=n;i++)
mp[make_pair(find1(i),find2(i))]++;
for(int i=1;i<=n;i++)
    if(i!=n)
    printf("%d ",mp[make_pair(find1(i),find2(i))]);
else
    printf("%d\n",mp[make_pair(find1(i),find2(i))]);
return 0;
}
