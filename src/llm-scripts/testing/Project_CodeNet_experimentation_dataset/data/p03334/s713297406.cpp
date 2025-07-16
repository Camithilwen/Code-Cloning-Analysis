#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 601, C = 2e5 + 7;
int sqr[C];
int n, num[N][N], d[2];
vector <int> g[2][N * N];
bool c[2][N * N], used[N * N];
void dfs(bool t, int u) {
    used[u] = 1;
    for (int v : g[t][u]) {
        if (!used[v]) {
            c[t][v] = c[t][u] ^ 1;
            dfs(t, v);
        }   
    }   
}   
vector <ii> ans[2][2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif        
    for (int i = 0; i < C; ++i) sqr[i] = -1;
    for (int i = 0; i < C; ++i) if (i * i < C) sqr[i * i] = i;
    cin >> n >> d[0] >> d[1];
    int p = 0;
    for (int i = 0; i < 2 * n; ++i) 
        for (int j = 0; j < 2 * n; ++j) 
            num[i][j] = p++;
    for (int t = 0; t < 2; ++t) {
        vector <ii> v;
        for (int i = 0; i * i <= d[t]; ++i) 
            if (sqr[d[t] - i * i] != -1) {
                v.app(mp(i, sqr[d[t] - i * i]));
                v.app(mp(i, -sqr[d[t] - i * i]));
                v.app(mp(-i, sqr[d[t] - i * i]));
                v.app(mp(-i, -sqr[d[t] - i * i]));
            }
        for (int i = 0; i < 2 * n; ++i) 
            for (int j = 0; j < 2 * n; ++j) 
                for (auto e : v) if (0 <= i + e.f && i + e.f < 2 * n && 0 <= j + e.s && j + e.s < 2 * n)
                    g[t][num[i][j]].app(num[i + e.f][j + e.s]);
        memset(used, 0, sizeof used);           
        for (int i = 0; i < 4 * n * n; ++i) 
            if (!used[i]) {
                dfs(t, i);
            }
    }    
    for (int i = 0; i < 4 * n * n; ++i) ans[c[0][i]][c[1][i]].app(mp(i / (n << 1), i % (n << 1)));
    for (int i = 0; i < 2; ++i) 
        for (int j = 0; j < 2; ++j) 
            if (ans[i][j].size() >= n) {
                cerr << Time << '\n';
                for (int k = 0; k < n * n; ++k) cout << ans[i][j][k].f << ' ' << ans[i][j][k].s << '\n';
                exit(0);   
            }
    exit(1);
}