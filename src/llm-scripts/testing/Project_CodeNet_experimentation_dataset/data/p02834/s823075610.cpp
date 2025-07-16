#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
using ull = uint64_t;
using ll = int64_t;
using PII = pair<int, int>;
using VI = vector<int>;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(A v) {
bool first = true; string res = "{";
for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); }
res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H); debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 100005;
vector<VI> tree;
int dist1[N], dist2[N];


void dfs(int v, int d, int from, int *arr) {
    arr[v] = d;
    for (int u : tree[v]) {
        if (u == from) continue;
        dfs(u, d + 1, v, arr);
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, u, v;
    cin >> n >> u >> v;
    tree.assign(n + 2, VI());
    REP(i, n - 1) {
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(u, 0, 0, dist1);
    dfs(v, 0, 0, dist2);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] < dist2[i]) {
            mx = max(mx, dist2[i]);
        }
    }
    cout << mx - 1 << "\n";
}