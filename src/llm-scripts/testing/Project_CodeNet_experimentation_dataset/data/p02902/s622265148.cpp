#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 1010;

int N, M;
vi G[MAX];

int pos = -1;
bool vis[MAX], fin[MAX];
vi hist;

int idx[MAX];

void dfs(int v) {
    vis[v] = true;
    hist.push_back(v);
    FORE (nv, G[v]) {
        if (fin[nv]) continue;
        if (vis[nv]) {
            pos = nv;
            return;
        }
        dfs(nv);
        if (pos != -1) return;
    }
    hist.pop_back();
    fin[v] = true;
}

void solve() {
    REP (v, N) {
        dfs(v);
        if (pos != -1) break;
    }

    if (pos == -1) {
        cout << -1 << endl;
        return;
    }

    vi cycle;
    while (!hist.empty()) {
        int t = hist.back();
        cycle.push_back(t);
        hist.pop_back();
        if (t == pos) break;
    }
    reverse(ALL(cycle));

    while(1) {
        bool done = false;
        REP (i, MAX) idx[i] = -1;
        REP (i, cycle.size()) idx[cycle[i]] = i;

        REP (i, cycle.size()) {
            int cur = cycle[i];
            FORE (next, G[cur]) if (idx[next] >= 0) {
                if (idx[next] == (idx[cur] + 1) % cycle.size()) continue;

                vi v;
                bool get = false;
                for (int r = 0;; r++) {
                    if (cycle[r%cycle.size()] == next) get = true;
                    if (get){
                        v.push_back(cycle[r%cycle.size()]);
                        if (cycle[r%cycle.size()] == cur) break;
                    } 
                }

                cycle = v;
                done = true;
                break;
            }
            if (done) break;
        }
        if (!done) break;
    }

    cout << cycle.size() << endl;
    FORE (r, cycle) cout << r+1 << "\n";
    return;
}

int main() {
    cin >> N >> M;
    REP (i, M) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
    }
    solve();
}