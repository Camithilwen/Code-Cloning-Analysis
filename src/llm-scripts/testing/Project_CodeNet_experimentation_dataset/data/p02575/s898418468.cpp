#include<bits/stdc++.h>
using namespace std;
#define hackcyborg shresth_walia
#define ll long long
#define ld double
#define pb push_back
#define mod 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
ll binpow(ll a,ll b,ll m=mod)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        res=(a*res)%m;
        a=(a*a)%m;
        b/=2;
    }
    return res;
}
const int INF =1e9;
ll n;
vector<pair<ll,ll>> ar[200010];
void dijkstra(int s, vector<int> & d, vector<int> & p) {
    d.assign(n+1, INF);
    p.assign(n+1, -1);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge : ar[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
main()
{
    IO
    ll m;
    cin>>n>>m;
    ++n;
    ll a[n+1],b[n+1];
    for(int x=1;x<n;x++)
        {cin>>a[x]>>b[x];
        ++b[x];}
    b[n]=m;
    a[n]=1;
    set<pair<ll,ll>> ae;
    for(int x=1;x<=m;x++)
    {
         ae.insert({x,0ll});
    }
    for(int x=1;x<=n;x++)
    {
        auto it=ae.lower_bound(make_pair(a[x],-1ll));
        vector<pair<ll,ll>> as;
        if(it!=ae.end())
        while((it->first)<=(b[x]-1) && (it->first)>=a[x])
        {
            as.pb(*it);
            //cout<<it->second<<" "<<x<<"\n";
            ar[it->second].pb(make_pair(x,abs(it->first-b[x])+abs(it->second-x)));
            ++it;
            if(it==ae.end())break;
        }
        for(auto it : as)
            ae.erase(it);
        ae.insert(make_pair(b[x],x));
    }
    vector<ll> d,p;
    dijkstra(0,d,p);
    ll ans[n+1];
    for(int x=1;x<=n;x++)
        ans[x]=INF;
    for(int x=0;x<=n;x++)
    {   ans[x]=min(ans[x],d[x]);
        for(auto it : ar[x])
        {
            ans[it.first]=min(ans[it.first],d[x]+abs(x-it.first));
        }
    }
    ll mi=1e18;
    for(int x=n;x>=1;x--)
    {
        ans[x]=min(ans[x],mi+x);
        mi=min(mi,ans[x]-x);
    }
    for(int x=2;x<=n;x++)
         if(ans[x]<1e8)
        cout<<ans[x]-1<<"\n";
         else
            cout<<-1<<"\n";
}
