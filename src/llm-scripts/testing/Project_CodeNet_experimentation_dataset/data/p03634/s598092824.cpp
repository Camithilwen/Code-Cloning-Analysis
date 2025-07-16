#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

struct edge
{
    int to;
    ll cost;
};
vector<vector<edge>> tree(100010);
vector<ll> depth(100010);

void dfs(int v, int p, ll d)
{ //vからの最短経路、現在地のいっこまえ、はじめからの距離
    depth[v] = d;
    for (auto &e : tree[v])
    {
        if (e.to == p)
            continue;
        dfs(e.to, v, d + e.cost);
    }
}

int main()
{
    int n;
    cin >> n;
    rep(i, n - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    int q, k;
    cin >> q >> k;
    k--;

    dfs(k, -1, 0);
    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << depth[x] + depth[y] << endl;
    }
}
