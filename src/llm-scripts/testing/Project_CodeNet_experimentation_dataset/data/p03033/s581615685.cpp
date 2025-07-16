#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, q, inf=2e9, cnt;
vector<int> par ;
vector<pair<int,pair<int,int> > > v;
map<int,int> id ;
int tree[3000006];
void update(int node, int s, int e, int l, int r, int val)
{
    if(s>r||e<l)
        return ;
    if(s>=l && e<=r)
    {
        tree[node]=min(tree[node],val);
        return ;
    }
    int m=(s+e)/2;
    update(2*node,s,m,l,r,val);
    update(2*node+1,m+1,e,l,r,val);
}
int solve(int node, int s,int e, int pos)
{
    if(s==e)
        return tree[node];
    int m=(s+e)/2;
    tree[2*node]=min(tree[node],tree[2*node]);
    tree[2*node+1]=min(tree[node],tree[2*node+1]);
    return pos<=m ? solve(2*node,s,m,pos) : solve(2*node+1,m+1,e,pos);
}
int main()
{
    IO
    cin>>n>>q;
    for(int i=1; i<=3e6; i++)
        tree[i]=inf;
    for(int i=1; i<=n; i++)
    {
        int s, t, x;
        cin>>s>>t>>x;
        v.push_back({x,{s-x,t-x-1}});
        id[s-x]++;
        id[t-x-1]++;
    }
    for(int i=1; i<=q; i++)
    {
        int d;
        cin>>d;
        id[d]++;
        par.push_back(d);
    }
    for(auto i : id)
        id[i.first]=++cnt;
    for(int i=0; i<n; i++)
    {
        int l=id[v[i].second.first], r=id[v[i].second.second];
        update(1,1,cnt,l,r,v[i].first);
    }
    for(int i=0; i<q; i++)
    {
        int ans=solve(1,1,cnt,id[par[i]]);
        if(ans==inf)
            ans=-1;
        cout<<ans<<"\n";
    }
}
