#include <bits/stdc++.h>                        
#define pb push_back                            
#define mp make_pair                            
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define jonathan ios_base::sync_with_stdio(0)
#define livingston cin.tie(0)
using namespace std;                            
                                                
void yes() {cout << "Yes" << endl;}                                               
void no() {cout << "No" << endl;}                                                        
                                                
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};         
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1}; 

const int INF = 1e9 + 9;
const long long LINF = 1e18 + 8;
const double EPS = 1e-9;
const long long MOD = 1e9 + 7; //998244353
const double PI = acos(-1);

vector<int> g[100010];
bool used[100010];

void dfs(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    k = min(n, k);
    vector<int> a(n + 1);
    vector<int> d(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = (a[1] != 1);
    a[1] = 1;
    for (int i = 1; i <= n; i++) {
        g[a[i]].push_back(i);
    }
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < sz(g[v]); i++) {
            int to = g[v][i];
            if (d[to] > d[v] + 1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = i + 1;
    }
    sort(all(s), [&](int x, int y) {
        return d[x] > d[y];
    });

    for (int i = 0; i < n; i++) {
        int v = s[i];
        if (used[v]) continue;
        for (int j = 0; j < k - 1; j++) {
            v = a[v];
        }
        dfs(v);
        if (a[v] != 1) {
            res++;
        }
    }

    cout << res << endl;
}   

int main() {
    jonathan; 
    livingston;
    solve();
    return 0;
}