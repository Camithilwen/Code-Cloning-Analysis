#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <cctype>
#include <cmath>
#include <bitset>

using namespace std;

/* typedef */
typedef long long ll;

/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 100000;
const int mod = 1000000007;
const double pi = 3.141592653589;

/* global variables */
vector<int> parent(MAX), prenum(MAX), lowest(MAX);
vector< vector<int> > Adj(MAX);
vector<bool> visited(MAX, false);
int N;
int timer;

/* function */
void dfs(int cur, int prev);
void art_points();

/* main */
int main() {
    int m;
    cin >> N >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }

    art_points();

}

void dfs(int cur, int prev) {
    // after visited node cur
    prenum[cur] = lowest[cur] = timer;
    timer++;
    visited[cur] = true;

    int next;
    for (int i = 0; i < Adj[cur].size(); i++) {
        next = Adj[cur][i];
        if ( !visited[next] ) {
            // before visiting next node
            parent[next] = cur;
            dfs(next, cur);
            // after visiting next node
            lowest[cur] = min(lowest[cur], lowest[next]);
        }
        else if (next != prev) {
            // Edge(cur, next) is Back-Edge
            lowest[cur] = min(lowest[cur], prenum[next]);
        }
    }
}

void art_points() {
    timer = 1;
    // calculate lowest
    dfs(0, -1); // 0 == root

    set<int> ap;
    int child_of_root = 0;
    for (int i = 1; i < N; i++) {
        int p = parent[i];
        if (p == 0) child_of_root++;
        else if (prenum[p] <= lowest[i]) ap.insert(p);
    }
    if (child_of_root >= 2) ap.insert(0);
    for (auto it = ap.begin(); it != ap.end(); it++) {
        cout << *it << '\n';
    }
}
