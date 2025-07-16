#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define endl        "\n"
#define P           pair<int, int>

const int mod = 1e9+7;

inline int add(int a, int b) { int res = a + b; if(res >= mod) res -= mod;  return res; }
inline int sub(int a, int b) { int res = a - b; if(res < 0) res += mod; return res;}
inline int mul(int a, int b) { return (a * b)%mod; }

int modpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b%2) ans = mul(ans, a);    
        b /= 2; a = mul(a, a);
    }   return ans;
}

const int N = 1e5+5;
vector<P> g[N];
int n;

bool cmp1(pair<int, P> a, pair<int, P> b) {
    return a.second.first < b.second.first;
}

bool cmp2(pair<int, P> a, pair<int, P> b) {
    return a.second.second < b.second.second;
}

int MST() {
    priority_queue<P, vector<P>, greater<P>> q;
    int cost = 0;
    q.push({0, 0});
    bool mark[N]; memset(mark, 0, sizeof mark);
    while(!q.empty()) {
        P tp = q.top(); q.pop();
        int cur = tp.second;
        if(mark[cur]) continue;
        cost += tp.first;
        mark[cur] = 1;
        for(auto ne : g[cur]) {
            int node = ne.second;
            if(mark[node] == false) q.push(ne);
        }
    }
    return cost;
}

void solve() {
    cin >> n;
    pair<int, P> a[n];
    for(int i=0; i<n; i++) {
        P p; cin >> p.first >> p.second;
        a[i] = make_pair(i, p);
    }
    sort(a, a+n, cmp1);
    for(int i=1; i<n; i++) {
        int d = a[i].second.first - a[i-1].second.first;
        int u = a[i-1].first, v = a[i].first;
        g[v].push_back({d, u});
        g[u].push_back({d, v});
    }
    sort(a, a+n, cmp2);
    for(int i=1; i<n; i++) {
        int d = a[i].second.second - a[i-1].second.second;
        int u = a[i-1].first, v = a[i].first;
        g[u].push_back({d, v});
        g[v].push_back({d, u});
    }

    cout << MST() << endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}