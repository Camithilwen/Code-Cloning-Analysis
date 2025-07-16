#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int N = 1e5 + 10;

int n, m, res[N], deg[N];
vector <int> adj[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    FOR(i, 1, m + n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    int root = 0;
    FOR(i, 1, n)
        if (deg[i] == 0)
            root = i;
    queue <int> Q;
    Q.push(root);
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v : adj[u])
            if (--deg[v] == 0){
                Q.push(v);
                res[v] = u;
            }
    }
    FOR(i, 1, n)
        cout << res[i] << endl;
}
