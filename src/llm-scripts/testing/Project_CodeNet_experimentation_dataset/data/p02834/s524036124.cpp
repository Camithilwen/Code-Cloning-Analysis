#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define rep(i,n) for(int64_t i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr int64_t INF=(1ll<<60);
constexpr int64_t mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

Graph G;
ll n;

void bfs(vector<ll> &dist,queue<ll> que,ll start){
    vector<bool> visit(n,false);
    que.push(start);

    while(!que.empty()){
        ll now=que.front();
        que.pop();
        visit[now]=true;
        for(ll next:G[now]){
            if(visit[next]==true) continue;

            visit[next]=true;
            que.push(next);

            dist[next]=dist[now]+1;
        }
    }

    return;
}

int main(){
    ll u,v;cin>>n>>u>>v;
    u--;v--;
    G.resize(n);
    rep(i,n-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<ll> que;
    vector<ll> takahashi(n),aoki(n);

    bfs(takahashi,que,u);
    bfs(aoki,que,v);

    ll ans=0,key=0;
    rep(i,n){
        if(aoki[i]>takahashi[i]){
            chmax(ans,aoki[i]);
        }
    }

    ans--;

    cout<<ans<<endl;
    return 0;
}