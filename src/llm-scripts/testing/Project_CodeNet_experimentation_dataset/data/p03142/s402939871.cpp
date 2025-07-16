#include <bits/stdc++.h>

using namespace std;
int u,v,kq,x[100005],y[100005],deg[100005],n,m,slx;
vector<int> a[100005],ng[100005];
queue<int> q;
void sxtp()
{
    for (int i=1;i<=n;++i) if (deg[i]==0) q.push(i);

    while (!q.empty())
    {

        int u=q.front();q.pop();
        x[++slx]=u;y[u]=slx;
        for (int i=0;i<a[u].size();++i)
        {
            int v=a[u][i];
            deg[v]--;
            if (deg[v]==0) q.push(v);
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n+m-1;++i)
    {
        cin>>u>>v;
        a[u].push_back(v);deg[v]++;
        ng[v].push_back(u);
    }
    sxtp();
    for (int u=1;u<=n;++u)
    {
        kq=0;
        for (int j=0;j<ng[u].size();++j)
        {
            v=ng[u][j];
           // if (u==1) cout<<v<<endl;
            if (y[v]>y[kq]) kq=v;
        }
        cout<<kq<<'\n';
    }
   // cout<<x[1]<<' '<<y[6]<<endl;


    return 0;
}
