#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//1000000000000223
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, vis[1009], vis2[1009],par[1009],go[1009][1009] ;
vector<int> v[1009];
vector<int> ans;
void solve()
{
    int sz=ans.size();
    for(int i=0; i<sz; i++)
    {
        for(int j=i+2; j<sz; j++)
            if(go[ans[i]][ans[j]])
            {
                ans.erase(ans.begin()+i+1,ans.begin()+j);
                solve();
                return ;
            }
        int j=0;
        if(i==sz-1)
            j=1;
        for(; j<i; j++)
            if(go[ans[i]][ans[j]])
            {
                ans.erase(ans.begin()+i+1,ans.end());
                ans.erase(ans.begin(),ans.begin()+j);
                solve();
                return ;
            }
    }
    cout<<ans.size()<<endl;
    for(auto i : ans)
        cout<<i<<"\n";
}
void dfs(int node)
{
    if(vis2[node])
    {
        int x=node;
        while(par[x]!=node)
            ans.push_back(x), x=par[x];
        ans.push_back(x);
        reverse(ans.begin(),ans.end());
        solve();
        exit(0);
    }
    if(vis[node])
        return ;
    vis2[node]++;
    vis[node]++;
    for(auto i : v[node])
    {
        par[i]=node;
        dfs(i);
    }
    vis2[node]--;
}
int main()
{
    IO
    cin>>n>>m;
    while(m--)
    {
        int x, y ;
        cin>>x>>y;
        go[x][y]=1;
        v[x].push_back(y);
    }
    for(int i=1; i<=n; i++)
        dfs(i);
    cout<<-1;
    return 0;
}
