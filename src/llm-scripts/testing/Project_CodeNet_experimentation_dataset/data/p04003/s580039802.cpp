#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back

int dp[300005];
vector<pii> g[300005];
vector<pii> edge[1000005];
int p[100005];
int idx[100005];
int root(int a){
    return p[a] == a?a:(p[a]=root(p[a]));
}
void merge(int a, int b){
    a = root(a), b = root(b);
    if(a != b) p[a] = b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[c].eb(mp(a, b));
    }
    int cnt = n+1;
    for(int i=1;i<=1000000;i++){
        vector<int> v;
        for(int j=0;j<sz(edge[i]);j++){
            int a = edge[i][j].fi, b = edge[i][j].se;
            merge(a, b);
            v.eb(a), v.eb(b);
        }
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        for(int i=0;i<sz(v);i++){
            int u = v[i];
            if(root(u) == u) idx[u] = cnt++;
        }
        for(int i=0;i<sz(v);i++){
            int u = v[i];
            g[u].eb(mp(idx[root(u)], 1));
            g[idx[root(u)]].eb(mp(u, 0));
        }
        for(int i=0;i<sz(v);i++) p[v[i]] = v[i];
    }
    deque<pii> dq;
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    dq.push_front(mp(dp[1], 1));
    while(!dq.empty()){
        int u = dq.front().se;
        int val = dq.front().fi;
        dq.pop_front();
        if(val != dp[u]) continue;
        for(int i=0;i<sz(g[u]);i++){
            int v = g[u][i].fi, w = g[u][i].se;
            if(dp[v] == -1 || dp[v] > dp[u] + w){
                dp[v] = dp[u] + w;
                if(w == 0) dq.push_front(mp(dp[v], v));
                else dq.push_back(mp(dp[v], v));
            }
        }
    }
    printf("%d\n", dp[n]);
}