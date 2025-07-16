#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

const int  MAX_V = 100000;
vector<int> es[MAX_V];
vector<int> col(MAX_V, -1);
bool loop = false;

void dfs(int now, int c){
    col[now] = c;
    for(auto &e: es[now]){
        if(col[e] == -1) dfs(e, c^1);
        if(col[e] == c) loop = true;
    }
}

int main(){
    ll N, M;
    cin >> N >> M;
    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        es[u].pb(v), es[v].pb(u);
    }
    dfs(0, 0);
    if(loop) cout << N*(N-1)/2-M << endl;
    else{
        ll a = 0, b = 0;
        rep(i, N) (col[i]? a : b)++;
        cout << a*b-M << endl;
    }
}