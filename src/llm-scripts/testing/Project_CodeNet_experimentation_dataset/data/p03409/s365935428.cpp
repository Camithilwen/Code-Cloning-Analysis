#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int N_MAX = 100;
const int INF = 1000000;

struct edge{
    int to, cap, rev;
    edge(int t, int c, int r): to(t), cap(c), rev(r){}
};

vector<edge> G[N_MAX * 2];
bool used[N_MAX * 2];

void add_edge(int from, int to, int cap){
    G[from].emplace_back(to, cap, G[to].size());
    G[to].emplace_back(from, 0, G[from].size()-1);
}

int dfs(int v, int t, int f){
    if (v == t) return f;
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    for(;;){
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> RED;
    vector<pair<int, int>> BLUE;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        RED.emplace_back(a, b);
    }
    for(int i = 0; i < n; i++){
        int c, d;
        cin >> c >> d;
        BLUE.emplace_back(c, d);
    }
    for(int i = 1; i <= n; i++){
        int a = RED[i-1].first, b = RED[i-1].second;
        for(int j = 1; j <= n; j++){
            int c = BLUE[j-1].first, d = BLUE[j-1].second;
            if (a < c && b < d){
                add_edge(i, n+j, 1);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        add_edge(0, i, 1);
        add_edge(n+i, 2 * n + 1, 1);
    }
    cout << max_flow(0, 2 * n + 1) << endl;
    return 0;
}