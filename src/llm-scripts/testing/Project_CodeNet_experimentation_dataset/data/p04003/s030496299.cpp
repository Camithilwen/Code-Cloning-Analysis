#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int N = 500005;
int n,m;
map<ii, int> id;
vector<ii> G[N];
int ct = 1;
priority_queue<ii, vector<ii>, greater<ii> > pq;
int dist[N];
int main(){
    scanf("%d%d",&n,&m);
    ct = n+1;
    for (int i = 0; i < m; i++){
        int p,q,c;
        scanf("%d%d%d",&p,&q,&c);
        int a,b;
        if (id.count({p,c})) a = id[ii(p,c)];
        else{
            a = id[ii(p,c)] = ct++;
            G[a].push_back({p,1});
            G[p].push_back({a,1});
        }
        if (id.count({q,c})) b = id[ii(q,c)];
        else{
            b = id[ii(q,c)] = ct++;
            G[b].push_back({q,1});
            G[q].push_back({b,1});
        }
        G[a].push_back({b,0});
        G[b].push_back({a,0});
    }
    memset(dist,-1,sizeof(dist));
    dist[1] = 0;
    pq.push({0,1});
    while (pq.size()){
        int d, u;
        tie(d,u) = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto v : G[u]){
            int nd = d + v.second;
            if (dist[v.first] == -1 || dist[v.first] > nd){
                dist[v.first] = nd;
                pq.push({nd,v.first});
            }
        }
    }
    if (dist[n] == -1) printf("-1\n");
    else printf("%d",dist[n]/2);




}
