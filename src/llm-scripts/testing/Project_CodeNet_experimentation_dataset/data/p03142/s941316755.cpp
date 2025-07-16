#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define fi first
#define se second
#define pb push_back
//#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 1e5 + 10;
const int oo = 1e18;

int n, m, root, cnt;
int deg[N], ans[N], dp[N], tpid[N], idtp[N];
bool check[N], visit[N];
vector<ii> child[N];
ii edge[N];
stack<int> st;

void dfs(int u) {
    visit[u] = 1;
    for(auto it: child[u])  if(!visit[it.fi])   {
        dfs(it.fi);
    }
    st.push(u);
}

void solve()    {
    dfs(root);
    while(!st.empty())  {
        tpid[st.top()] = ++cnt;
        idtp[cnt] = st.top();
        st.pop();
    }

    FOR(i, 1, n) dp[i] = -1;
    dp[1] = 0;
    FOR(i, 1, n)    {
        int u = idtp[i];
        for(auto it: child[u]) if(dp[tpid[it.fi]] < dp[i] + 1)
            dp[tpid[it.fi]] = dp[i] + 1;
    }
//    FOR(i, 1, n) cout << dp[tpid[i]] << ' '; cout << '\n';
    FOR(i, 1, n)    {
        for(auto it: child[i]) if(dp[tpid[it.fi]] - dp[tpid[i]] > 1)
            check[it.se] = 1;
    }
    FOR(i, 1, n - 1 + m)    if(!check[i])
        ans[edge[i].se] = edge[i].fi;
    FOR(i, 1, n) cout << ans[i] << '\n';
}

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
//    ios_base::sync_with_stdio(false); cout.tie(0);

    scanf("%d%d", &n, &m);
    FOR(i, 1, n - 1 + m)    {
        int u, v; scanf("%d%d", &u, &v);
        edge[i] = {u, v};
        child[u].pb({v, i});
        deg[v] ++;
    }

    FOR(i, 1, n) if(deg[i] == 0) root = i;

    return solve(), 0;
}
