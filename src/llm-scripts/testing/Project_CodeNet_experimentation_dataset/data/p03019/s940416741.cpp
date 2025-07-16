#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int n,x;
int b[Maxn],l[Maxn],r[Maxn];
bool flag[Maxn];
priority_queue<pair<long long,int> >pq;
long long solve(int id,long long tmp)
{
    if (tmp<=0LL) return 0LL;
    if (tmp<=1LL*l[id]*b[id])
    {
        return (tmp+l[id]-1)/l[id];
    } else
    {
        tmp-=1LL*l[id]*b[id];
        return (tmp+r[id]-1)/r[id]+b[id];
    }
}
int main()
{
    scanf("%d%d",&n,&x);
    while (!pq.empty()) pq.pop();
    long long tmp=0LL;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&b[i],&l[i],&r[i]);
        tmp+=1LL*l[i]*b[i];
        pq.push(make_pair(1LL*r[i]*(x-b[i])+1LL*l[i]*b[i],i));
    }
    long long ans=1LL*x*n;
    int cnt=0;
    while ((!pq.empty())&&tmp>=0)
    {
        tmp-=pq.top().first;
        int id=pq.top().second;
        flag[id]=true;
        pq.pop();
        ++cnt;
    }
    ans=min(ans,1LL*cnt*x);
    --cnt;
    long long t=x;
    for (int i=1;i<=n;i++)
        if (flag[i])
        {
            tmp+=1LL*r[i]*(x-b[i])+1LL*l[i]*b[i];
            t=min(t,solve(i,tmp));
            tmp-=1LL*r[i]*(x-b[i])+1LL*l[i]*b[i];
        }
    ans=min(ans,1LL*cnt*x+t);
    while (!pq.empty()) pq.pop();
    tmp=0LL;
    for (int i=1;i<=n;i++)
    {
        tmp+=1LL*l[i]*b[i];
        pq.push(make_pair(1LL*r[i]*(x-b[i])+1LL*l[i]*b[i],i));
    }
    memset(flag,false,sizeof(flag));
    cnt=0;
    while ((!pq.empty())&&tmp>pq.top().first)
    {
        tmp-=pq.top().first;
        int id=pq.top().second;
        flag[id]=true;
        pq.pop();
        ++cnt;
    }
    ans=min(ans,1LL*cnt*x+x);
    t=x;
    for (int i=1;i<=n;i++)
        if (!flag[i]) t=min(t,solve(i,tmp));
    ans=min(ans,1LL*cnt*x+t);
    printf("%lld\n",ans);
    return 0;
}