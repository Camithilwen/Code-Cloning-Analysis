//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define Mp make_pair

typedef pair < int , int > pii;

const int N = 2e5 + 10;

int mark[N], cmp[2][N];
vector < int > adj[2][N];
map < pii , int > mp;

void dfs(int v, int t, int c){
    mark[v] = 1;
    cmp[t][v] = c;
    for (int u : adj[t][v])
        if (!mark[u])
            dfs(u, t, c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 0; i < m1; i ++){
        int u, v;
        cin >> u >> v;
        adj[0][u].pb(v);
        adj[0][v].pb(u);
    }
    for (int i = 0; i < m2; i ++){
        int u, v;
        cin >> u >> v;
        adj[1][u].pb(v);
        adj[1][v].pb(u);
    }
    int c = 0;
    for (int i = 1; i <= n; i ++)
        if (!mark[i])
            dfs(i, 0, c ++);
    fill(mark, mark + N, 0);
    c = 0;
    for (int i = 1; i <= n; i ++)
        if (!mark[i])
            dfs(i, 1, c ++);
    for (int i = 1; i <= n; i ++)
        mp[Mp(cmp[0][i], cmp[1][i])] ++;
    for (int i = 1; i <= n; i ++)
        cout << mp[Mp(cmp[0][i], cmp[1][i])] << ' ';
    return 0;
}
