#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

const int INF = 1001001001;
int n;
vector<int> to[1005];

vector<int> bfs(int sv) {
    vector<int> dist(n,INF), pre(n,-1);
    queue<int> q;
    dist[sv] = 0;
    q.push(sv);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : to[v]) {
            if(dist[u] != INF) continue;
            pre[u] = v;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    pair<int, int> best(INF, -1);
    rep(v,n) {
        if (v == sv) continue;
        for (int u : to[v]) {
            if (u == sv) {
                best = min(best, make_pair(dist[v],v));
            }
        }
    }
    if(best.first == INF) return vector<int>(n+1);
    int v = best.second;
    vector<int> res;
    while(v != -1){
        res.push_back(v);
        v = pre[v];
    }
    return res;
}

int main(){
    int m;
    cin >> n >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }

    vector<int> ans(n+1);
    rep(s, n){
       auto now =  bfs(s);
       if(now.size() < ans.size()) ans = now;
    }
    if(ans.size() == n + 1){
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for (int v: ans){
        cout << v+1 << endl;
    }
    
}