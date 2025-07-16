#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+2;
int pre1[MAXN],pre2[MAXN];
int finds(int x,int *pre)
{
    return pre[x] == x? pre[x]:pre[x] = finds(pre[x],pre);
}
void join(int x,int y,int *pre)
{
    int px = finds(x,pre);
    int py = finds(y,pre);
    if( px!=py)
    {
        pre[px] = py;
    }
}
int main()
{
    int n,k,l;
    cin>>n>>k>>l;
    for(int i = 1;i<=n;i++)
        pre1[i] = i,pre2[i] = i;
    for(int i = 1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        join(x,y,pre1);
    }
    for(int i = 1;i<=l;i++)
    {
        int x,y;
        cin>>x>>y;
        join(x,y,pre2);
    }
    for(int i = 1;i<=n;i++)
    {
        finds(i,pre1);
        finds(i,pre2);
    }
    map<pair<int,int>,int> mp;
    for(int i = 1;i<=n;i++)
    {
        mp[make_pair(pre1[i],pre2[i])] ++;
    }
    for(int i = 1;i<=n;i++)
    {
        cout<<mp[make_pair(pre1[i],pre2[i])]<<" ";
    }
    cout<<endl;
}