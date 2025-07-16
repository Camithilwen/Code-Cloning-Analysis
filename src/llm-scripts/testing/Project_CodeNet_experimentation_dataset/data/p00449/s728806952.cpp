#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 700000000

using namespace std;

vector<pair<int, int>> adj[110];

int solve (int x, int d)
{
    int dst[110];
    bool done[110];
    priority_queue<pair<int, int>> que;
    for (int i=0; i<110; i++) dst[i]=INF;
    memset(done, false, sizeof(done));
    dst[x]=0;
    que.push({0,x});
    while (!que.empty())
    {
        int a=que.top().second;
        que.pop();
        if (done[a]) continue;
        done[a]=true;
        for (auto u : adj[a])
        {
            int b=u.first, w=u.second;
            if (dst[a]+w<dst[b])
            {
                dst[b]=dst[a]+w;
                que.push({-dst[b], b});
            }
        }
    }
    if (dst[d]==INF) return -1;
    else return dst[d];
}

int main()
{
    while (1)
    {
        for (int i=0; i<110; i++) adj[i].clear();
        int n, k, a, b, c, d;
        bool ok;
        cin>>n>>k;
        if (n==0 && k==0) break;
        for (int i=0; i<k; i++)
        {
            cin>>a>>b>>c;
            if (a==0)
            {
                cout<<solve(b,c)<<'\n';
            }
            else
            {
                cin>>d;
                ok=true;
                for (auto itr=adj[b].begin(); itr!=adj[b].end(); itr++)
                {
                    if (itr->first==c)
                    {
                        itr->second=min(itr->second, d);
                        ok=false;
                    }
                }
                if (ok) adj[b].push_back({c,d});
                ok=true;
                for (auto itr=adj[c].begin(); itr!=adj[c].end(); itr++)
                {
                    if (itr->first==b)
                    {
                        itr->second=min(itr->second, d);
                        ok=false;
                    }
                }
                if (ok) adj[c].push_back({b,d});
            }
        }
    }
    return 0;
}

