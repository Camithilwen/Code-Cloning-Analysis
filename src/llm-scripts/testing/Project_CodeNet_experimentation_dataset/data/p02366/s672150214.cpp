#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD 1000000007
#define INF 1e9
#define INFL 1e12
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} cout << a[a.size()-1] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef pair<int, bool> edge;

int v, e;
vector<vector<edge>> G;
vector<int> ord, low;
set<int> ans;
vector<bool> seen;
int k;
int zero_degree;

void dfs(int u){
    // pr(u);
    seen[u] = true;
    ord[u] = k; k++;
    low[u] = ord[u];
    for(edge &ed: G[u]){
        int v = ed.first;
        if(!seen[v]){
            ed.second = true;
            dfs(v);
            chmin(low[u], low[v]);
            if(u!=0 && ord[u] <= low[v] && ans.find(u)==ans.end()){
                // printf("(%d %d) is pushed\n", u, v);
                ans.insert(u);
            }
            // printf("(%d: %d %d) ",u, ord[u], low[u]);
            // printf("(%d %d)", ord[u], low[u]);
        }else if(ed.second==false){
            // if(ord[u]==low[v]) continue;
            chmin(low[u], ord[v]);
        }
    }
    // printf("(%d: %d %d) ",u, ord[u], low[u]);
}
 
int main()
{
    cin >> v >> e;
    // cout << v << " " << e << endl;
    G.resize(v); ord.resize(v), low.resize(v); seen.resize(v);

    int a, b;
    rep(i, e){
        cin >> a >> b;
        G[a].push_back({b, false});
        G[b].push_back({a, false});
    }
    // cout << G.size();
    // rep(i, v){
    //     for(auto ed: G[i]){
    //         printf("(%d %d) ", i, ed.first);
    //     }
    //     printf("\n");
    // }
    rep(i, v) seen[i]=false;
    int k = 0;

    dfs(0);

    // cout << endl;
    // rep(i, v){
    //     printf("(%d: %d %d) ",i, ord[i], low[i]);
    // }
    // cout << ans.size() << endl;
    int tmp=0;
    // printf("\n");
    for(edge ed: G[0]){
        // printf("%d\n", ed.second);
        if(ed.second) tmp++;
    }
    if(tmp>1) ans.insert(0);

    for(int i: ans){
        pr(i);
    }
    return 0;
}
