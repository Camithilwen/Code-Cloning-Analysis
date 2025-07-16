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

vector<pii> g[100005];
vector<int> cur[100005];
int dp[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(mp(b, c));
        g[b].eb(mp(a, c));
    }

    memset(dp, -1, sizeof(dp));
    priority_queue<pii> dq;
    // deque<pii> dq;
    dp[1] = 1;
    dq.push(mp(-dp[1], 1));
    for(int i=1;i<=1000000;i++) cur[1].eb(i);
    while(!dq.empty()){
        int u = dq.top().se;
        int val = -dq.top().fi;
        dq.pop();

        if(val != dp[u]) continue;

        sort(all(cur[u]));
        for(int i=0;i<sz(g[u]);i++){
            int v = g[u][i].fi, c = g[u][i].se;
            if(binary_search(all(cur[u]), c)){
                if(dp[v] == -1 || dp[v] > dp[u]){
                    cur[v].clear();
                    cur[v].eb(c);
                    dp[v] = dp[u];
                    dq.push(mp(-dp[v], v));
                }
                else if(dp[v] == dp[u]){
                    cur[v].eb(c);
                }
            }
            else{
                if(dp[v] == -1 || dp[v] > dp[u] + 1){
                    cur[v].clear();
                    cur[v].eb(c);
                    dp[v] = dp[u] + 1;
                    dq.push(mp(-dp[v], v));
                }   
                else if(dp[v] == dp[u] + 1){
                    cur[v].eb(c);
                }
            }
        }
    }
    printf("%d\n", dp[n]);
}