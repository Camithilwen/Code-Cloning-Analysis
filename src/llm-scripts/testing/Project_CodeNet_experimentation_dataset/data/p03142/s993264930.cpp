#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(),x.end()
#define sz(x)   (int)x.size()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<int,int>   ii;

vector<int> g[N];

int par[N];
int deg[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    int m;  cin >> m;

    for(int i = 1 ; i < n + m ; ++i)    {
        int x;  cin >> x;
        int y;  cin >> y;

        g[x].pb(y);
        deg[y]++;
    }
    queue<int>  qu;
    vector<int> tp;

    for(int i = 1 ; i <= n ; ++i)
        if(!deg[i]) qu.push(i);

    while (qu.size())   {
        int u = qu.front(); qu.pop();

        tp.pb(u);

        for(int v : g[u])   {
            deg[v]--;
            if(!deg[v])
                qu.push(v);
        }
    }
    for(int x : tp)
    for(int v : g[x])
        par[v] = x;

    for(int i = 1 ; i <= n ; ++i)
        cout << par[i] << "\n";
}
