#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define lli long long int
#define pii pair<int,int>
#define add(a,b) ((int) (((lli) (a) + (b))%MOD))
#define mul(a,b) ((int) (((lli) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N, u, v;
vector<int> graph [100000];
int visited [100000][2];
// Helper Functions

void dfs(int node, int dist, int ind) {
    visited[node][ind] = dist;
    for (int neigh: graph[node]) {
        if (visited[neigh][ind] != -1) continue;
        visited[neigh][ind] = dist+1;
        dfs(neigh, dist+1, ind);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> u >> v;
    u--; v--;
    memset(visited, -1, sizeof(int)*N*2);
    F0R(i,N-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    dfs(u,0,0);
    dfs(v,0,1);
    int ans = 0;
    F0R(i,N) {
        // cout << i+1 << ' ' << visited[i][0] << ' ' << visited[i][1] << '\n';
        if (visited[i][0] < visited[i][1]) {
            ans = max(ans, visited[i][1]-1);
        }
    }
    cout << ans << '\n';
}

// even diff = -1. odd diff rts