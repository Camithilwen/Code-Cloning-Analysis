#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

using Edge = pair<ll,ll>;
using Graph = vector<vector<Edge>>;

int N;
Graph G;
vector<ll> res;

void bfs(ll v) {

    queue<vector<ll>> que;
    que.push({v,-1,0});

    while(que.size()) {
        auto p = que.front();
        que.pop();

        if (p[1]!=-1) {
            res[p[0]] = res[p[1]] + p[2];
        }
        else {
            res[p[0]] = 0;
        }
        
        for (auto e:G[p[0]]) {
            if (res[e.first]==-1) que.push({e.first, p[0], e.second});
        }
    }
}

int main(){
    cin >> N;
    G.assign(N, vector<Edge>());
    for (int i=0; i<N-1; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    res.assign(N,-1);

    int Q,K;
    cin >> Q >> K;
    K--;

    bfs(K);

    rep(i,Q) {
        int x,y;
        cin >> x >> y;
        x--,y--;
        cout << res[x] + res[y]   << endl;
    }
}