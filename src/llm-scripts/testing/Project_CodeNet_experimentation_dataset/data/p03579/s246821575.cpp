#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX_V = 100005;

vector<int> G[MAX_V];
vector<int> color(MAX_V);

// 辺に属性がある場合
/*
struct edge {int to,cost;};
vector<edge> G[MAX_V];
*/

// 2部グラフの場合: b*w - m 2部グラフでない場合: n(n-1)/2 - m
bool dfs(int v, int c){
    color[v] = c;
    rep(i, G[v].size()){
        if(color[G[v][i]] == c) return false;
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;
}

int main(){
    ll N, M;
    cin >> N >> M;
    rep(i, M){
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        // 無向グラフの場合
        G[t].push_back(s);
    }

    // グラフの操作
    ll B = 0, W = 0;
    if(dfs(0, 1)){
        rep(i, N){
            if(color[i] == 1){
                B++;
            }
            else if(color[i] == -1){
                W++;
            }
        }
        cout << B*W - M << endl;
    }
    else {
        cout << ((N * (N-1)) / 2) - M << endl;
    }
}