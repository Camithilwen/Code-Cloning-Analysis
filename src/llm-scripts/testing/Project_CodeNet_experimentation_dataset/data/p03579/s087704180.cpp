#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i <= n; i++)
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<29;
const ll LINF = 1LL<<58;
const int mod = 1000000007;

int used[2][100010] = {0};
int color[2] = {0};
vector<int> G[100010];

void dfs(int v, int c){
    used[c][v]++;
    color[c]++;
    for(auto x: G[v]){
        if(used[c ^ 1][x]) continue;
        dfs(x, c^1);
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0, 0);
    ll ans = 0;

    if(used[0][0] * used[1][0]) {
        cout << (ll)n * (n - 1) / 2 - m << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int b = used[0][i], w = used[1][i];
        ans += b * (color[1] - G[i].size()) + w * (color[0] - G[i].size());
    }
    ans /= 2;

    cout << ans << endl;
    return 0;
}
