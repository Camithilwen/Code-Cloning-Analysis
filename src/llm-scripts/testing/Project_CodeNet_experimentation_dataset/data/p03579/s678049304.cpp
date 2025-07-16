#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

Graph G;
//2部グラフ判定
vector<ll> color; //1と-1に塗り分ける
bool ok = true;
int dfs(ll v, ll c)
{
    color[v] = c;
    rep(i, G[v].size())
    {
        if (color[G[v][i]] == 0)
            dfs(G[v][i], -c);
        else if (color[G[v][i]] == c)
            ok = false;
    }
    return 0;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    G.resize(n);
    color.resize(n);
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, 1);
    ll b = 0;
    rep(i, n) if (color[i] == 1) b++;
    if (ok)
        cout << b * (n - b) - m << endl;
    else
        cout << n * (n - 1) / 2 - m << endl;
}