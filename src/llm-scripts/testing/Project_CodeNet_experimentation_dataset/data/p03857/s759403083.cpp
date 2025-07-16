#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int> >adj1,adj2;
map<int,int>mm;
int vis[200005];
int vis2[200005];
vector<int>comp;
int ans[200005];
int parent[200005];

void dfs(int ver)
{
    comp.push_back(ver);
    vis[ver]=1;
    for(auto i:adj1[ver])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
}
vector<int>temp;


void dfs2(int ver,int dest)
{
    parent[ver]=dest;
    vis2[ver]=1;
    for(auto i:adj2[ver])
    {
        if(!vis2[i])
            dfs2(i,dest);
    }
}

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n,k,l;
    cin>>n>>k>>l;
    int x,y;
    adj1.resize(n+1);
    adj2.resize(n+1);
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        adj1[x].push_back(y);
        adj1[y].push_back(x);
    }
    for(int i=0;i<l;i++)
    {
        cin>>x>>y;
        adj2[x].push_back(y);
        adj2[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis2[i])
            dfs2(i,i);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            comp.clear();
            mm.clear();
            dfs(i);
            for(auto j:comp)
            {
                mm[parent[j]]++;
            }
            for(auto j:comp)
            {
                ans[j]=mm[parent[j]];
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
            cout<<ans[i]<<" ";
    }


} 

