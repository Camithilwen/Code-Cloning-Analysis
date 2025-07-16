#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge{
    int to;
    int cap;
    int rev;
};
struct Dinic{
    int V;
    vector<int> level, used;
    vector<vector<edge>> G;
    Dinic(int N){
        V = N;
        used.resize(V, 0);
        level.resize(V, -1);
        G.resize(V);
    }
    void add(int u, int v, int c){
        edge e1 = {v, c, (int)G[v].size()};
        G[u].push_back(e1);
        edge e2 = {u, 0, (int)G[u].size() - 1};
        G[v].push_back(e2);
    }
    void bfs(int s){
        level.assign(V, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(edge e: G[v]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    int dfs(int s, int t, int f){
        if(s == t) return f;
        for(int &i = used[s]; i < (int)G[s].size(); i++){
            edge &e = G[s][i];
            if(e.cap > 0 && level[e.to] > level[s]){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    int solve(int s, int t){
        int flow = 0;
        int INF = 1e9;
        while(1){
            bfs(s);
            if(level[t] < 0) return flow;
            used.assign(V, 0);
            int f;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
    }
};

int main(){
    int N;
    cin >> N;
    Dinic Ford(2 * N + 2);
    int can[N][N];//can[i][j] = 1でペアが作れる
    vector<int> a(N), b(N), c(N), d(N);
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < N; i++) cin >> c[i] >> d[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i] < c[j] && b[i] < d[j]) can[i][j] = 1;
            else can[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        Ford.add(2 * N, i, 1);
        Ford.add(N + i, 2 * N + 1, 1);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(can[i][j]) Ford.add(i, N + j, 1);
        }
    }
    int ans = Ford.solve(2 * N, 2 * N + 1);
    cout << ans << endl;
}