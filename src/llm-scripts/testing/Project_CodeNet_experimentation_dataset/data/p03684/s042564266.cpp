#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back

vector<pair<pair<int,int>,int> > v1,v2;
bool is_reach[100100];
int po_v1[100100]; // id
int po_v2[100100]; // id
priority_queue<pair<int,pair<int,int> > > pq;
int n;

int fi_dif(int a,int b)
{
    return abs(a-b);
}

void add_path(int who)
{
    if(po_v1[who]!=0&&!is_reach[v1[po_v1[who]-1].S])
    {
        pq.push({-fi_dif(v1[po_v1[who]].F.F,v1[po_v1[who]-1].F.F),{who,v1[po_v1[who]-1].S}});
    }
    if(po_v1[who]!=n-1&&!is_reach[v1[po_v1[who]+1].S])
    {
        pq.push({-fi_dif(v1[po_v1[who]].F.F,v1[po_v1[who]+1].F.F),{who,v1[po_v1[who]+1].S}});
    }
    if(po_v2[who]!=0&&!is_reach[v2[po_v2[who]-1].S])
    {
        pq.push({-fi_dif(v2[po_v2[who]].F.F,v2[po_v2[who]-1].F.F),{who,v2[po_v2[who]-1].S}});
    }
    if(po_v2[who]!=n-1&&!is_reach[v2[po_v2[who]+1].S])
    {
        pq.push({-fi_dif(v2[po_v2[who]].F.F,v2[po_v2[who]+1].F.F),{who,v2[po_v2[who]+1].S}});
    }
}

main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v1.PB({{a,b},i});
        v2.PB({{b,a},i});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=0;i<n;i++)
    {
        po_v1[v1[i].S]=i;
        po_v2[v2[i].S]=i;
    }
    int ans=0;
    is_reach[0]=true;
    add_path(0);
    while(!pq.empty())
    {
        int cost=-pq.top().F;
        int a=pq.top().S.F;
        int b=pq.top().S.S;
        pq.pop();
        if(is_reach[b])
            continue;
        ans+=cost;
        // printf("%d %d %d\n",cost,a,b);
        is_reach[b]=true;
        add_path(b);
    }
    printf("%d\n",ans);
}
