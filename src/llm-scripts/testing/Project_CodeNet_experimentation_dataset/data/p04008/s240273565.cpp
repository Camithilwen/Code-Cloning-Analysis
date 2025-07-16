#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int>> adj;
int dp[100005];
int k,ans=0;
int parent[1000005];
void dfs(int ver,int pr)
{
    parent[ver]=pr;
    int mx=-1;
    for(auto i:adj[ver])
    {
        dfs(i,ver);
        mx=max(mx,dp[i]);
    }
    dp[ver]=mx+1;
    if(dp[ver]==k-1 &&parent[ver]!=1)
    {
        dp[ver]=-1;        
        ans++;
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

    int n;
    cin>>n>>k;
    adj.resize(n+1);
    int x;
    cin>>x;
    fill_n(dp,100004,-1);
    if(x!=1)
            ans++;
                
    for(int i=0;i<n-1;i++)
    {
        cin>>x;
        adj[x].push_back(i+2);
    }
    dfs(1,1);
    cout<<ans;

} 
