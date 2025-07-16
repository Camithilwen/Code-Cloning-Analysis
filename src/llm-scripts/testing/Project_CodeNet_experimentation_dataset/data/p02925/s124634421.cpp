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

vector<PII> G[1005][1005];
int dist[1005][1005];
bool visited[1005][1005];
bool cycleFound;


int dfs(PII v) {
    if (visited[v.first][v.second]) {
        cycleFound = true;
        return 0;
    }
    if (SZ(G[v.first][v.second]) == 0) {
        return 1;
    }
    visited[v.first][v.second] = true;
    if (dist[v.first][v.second] != -1) return dist[v.first][v.second];
    int d = 0;
    for (auto p : G[v.first][v.second]) {
        d = max(d, dfs(p));
    }
    visited[v.first][v.second] = false;
    return dist[v.first][v.second] = d + 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    int totalM = (N * (N - 1)) / 2;
    vector<VI> V(N + 1, VI(N - 1));
    FOR(i, 1, N) REP(j, N - 1) cin >> V[i][j];
    memset(dist, -1, sizeof(dist));
    FOR(i, 1, N) {
        REP(j, N - 2) {
            int p = V[i][j];
            int q = V[i][j + 1];
            G[min(i, p)][max(i, p)].pb({min(i, q), max(i, q)});
        }
    }

    int d = 0;

    FOR(i, 1, N) {
        int p = V[i][0];
        d = max(d, dfs({min(i, p), max(i, p)}));
        if (cycleFound) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << d << "\n";

}
