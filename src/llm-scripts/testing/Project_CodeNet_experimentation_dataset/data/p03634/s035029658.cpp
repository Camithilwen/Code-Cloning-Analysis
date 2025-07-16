#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

vector< pair<int,int> > adj[100010];
ll sum[100010];

void dfs(int u,ll curSum,int prv)
{
    sum[u] = curSum;
    for (auto it : adj[u]) if (it.first != prv)
    {
        dfs(it.first,curSum + it.second,u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ; i < n ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int q,k;
    cin >> q >> k;
    dfs(k,0,-1);
    while (q--)
    {
        int u,v;
        cin >> u >> v;
        ll ans = sum[u] + sum[v];
        cout << ans << endl;
    }
    return 0;
}