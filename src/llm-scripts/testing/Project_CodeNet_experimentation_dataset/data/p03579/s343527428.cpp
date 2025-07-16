#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin(), v.end()
#define inputv(v, n)                                                           \
    vl v;                                                                      \
    rep(i, n) {                                                                \
        ll x;                                                                  \
        cin >> x;                                                              \
        v.push_back(x);                                                        \
    }
bool chmin(ll& a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
bool chmax(ll& a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans;
struct Gragh {
    ll N;
    vector<vl> G;
    vl visited;

    Gragh(ll n) {
        N = n;
        G.resize(N);
        resetv();
    }

    void add(ll a, ll b) { G[a].push_back(b); }

    void resetv(void) { visited = vl(N, 0); }

    //重さ無し
    void dfs(ll x) {
        visited[x] = 1;
        for (ll i : G[x]) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
    }
};
int main() {
    cin >> n >> m;
    Gragh G(2 * n);
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        G.add(a * 2, b * 2 + 1);
        G.add(b * 2, a * 2 + 1);
        G.add(a * 2+1, b * 2);
        G.add(b * 2+1, a * 2);
    }
    
    G.dfs(0);
    vl dp(2, 0);
    rep(i, n * 2) {
        if (G.visited[i] == 1)dp[i % 2]++;
    }

    
    x=dp[0];
    y=dp[1];
    k=x+y-n;
    ans=k*(n-k)+k*(k-1)/2+(x-k)*(y-k)-m;

    cout << ans << endl;
}