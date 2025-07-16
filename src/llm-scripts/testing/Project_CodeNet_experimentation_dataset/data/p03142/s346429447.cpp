#define task "test"

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

const ll LINF = 1E18;
const int INF = 1E9;
const int MOD = 1E9 + 7;
const int N = 2E5 + 5;

int t = 1;

int n, m, nump[N], pa[N];
bool avail[N];
vector <int> A[N];
set <ii> S[N];

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n + m - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        A[u].pb(v);
        nump[v]++;
    }
}

void Prepare()
{
    /*for (int u = 1; u <= n; u++) {
        for (int v : A[u]) S[u].insert({nump[v], v});
    }*/
}

void DFS(int u, int p)
{
    pa[u] = p;
    avail[u] = 0;

    for (int v : A[u]) if (v != p) {
        nump[v]--;
    }
    for (int v : A[u]) if (v != p && avail[v] && !nump[v]) DFS(v, u);
}

void Solve()
{
    int root = 0;
    for (int i = 1; i <= n; i++) if (!nump[i]) root = i;
    memset(avail, 1, sizeof(avail));
    DFS(root, 0);

    for (int i = 1; i <= n; i++) printf("%d\n", pa[i]);
}

int main()
{
    if (fopen(task ".inp","r")){
        freopen(task ".inp","r",stdin);
        freopen(task ".out","w",stdout);
    }
    // cin >> t;
    while (t--) {
        Input();
        Prepare();
        Solve();
    }
}

