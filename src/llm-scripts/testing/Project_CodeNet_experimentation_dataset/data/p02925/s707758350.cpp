#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

struct topological_sort{
    vector<vector<int>> G;
    vector<int> indegree;
    vector<int> degree;
    int V;

    topological_sort(int V) : V(V) {
        G.resize(V); 
        indegree.resize(V);
        degree.resize(V);
    }
    void add_edge(int a, int b) {
        G[a].push_back(b);
        indegree[b]++;
    }
    vector<int> sort() {
        queue<int> q;
        vector<int> sorted;
        int deg = 1;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                degree[i] = deg;
            }
        }
        while (!q.empty()) {
            queue<int> q_tmp;
            deg++;
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (int i = 0; i < G[v].size(); i++) {
                    int u = G[v][i];
                    indegree[u]--;
                    if (indegree[u] == 0) {
                        q_tmp.push(u);
                        degree[u] = deg;
                    }
                }
                sorted.push_back(v);
            }
            swap(q,q_tmp);
        }
        return sorted;
    }
};

int main() {
    int n; cin >> n;
    topological_sort ts(n*(n-1)/2);
    vvint to(n,vint(n));
    int num = 0;
    rep(i,n)rep(j,i) to[j][i] = to[i][j] = num++;
    vvint data(n,vint(n-1));
    rep(i,n)rep(j,n-1) {
        int x; cin >> x;
        x--;
        data[i][j] = x;
    }
    rep(i,n)rep(j,n-2) {
        ts.add_edge(to[i][data[i][j]],to[i][data[i][j+1]]);
    }
    vint res = ts.sort();
    if (res.size() != n*(n-1)/2) {cout << -1 << endl; return 0;}
    cout << ts.degree[res.back()] << endl;
}