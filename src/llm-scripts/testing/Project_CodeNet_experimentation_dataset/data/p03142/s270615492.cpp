///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           node(a,b,c)                 mp(mp(a,b),c)
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
vector<int>adj[M];
int n,m;
int in[M];
int par[M];
void dfs(int u)
{
    for(auto v:adj[u])
    {
         if(in[v]==1)
         {
             par[v]=u;
         }
         else
         {
             in[v]--;
         }
    }
    for(auto v:adj[u])
    {
        if(par[v]==u)
        {
            dfs(v);
        }
    }
}
 main()

{
    fast
    cin>>n>>m;
    f(i,1,n-1+m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        in[v]++;
    }
    int root=0;
    f(i,1,n)
    {
        if(in[i]==0)root=i;
    }
    dfs(root);
    f(i,1,n)
    {
        cout<<par[i]<<"\n";
    }
    return 0;

}



































