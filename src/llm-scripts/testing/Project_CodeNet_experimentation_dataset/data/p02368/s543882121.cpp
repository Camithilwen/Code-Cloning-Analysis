#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <tuple>
#include <string.h>
#include <map>
#include <iomanip>
#include <time.h>
using namespace std;
typedef long long ll;

int n, m, id[100010];
bool vis[100010];
vector<int> G[100010], R[100010], po;

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (auto& i : G[v]) dfs(i);
    po.push_back(v);
}

void rev_dfs(int v, int num) {
    if (vis[v]) return;
    vis[v] = true;
    id[v] = num;
    for (auto& i : R[v]) rev_dfs(i, num);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        R[b].push_back(a);
    }

    for (int i = 0; i < n; i++) dfs(i);
    for (int i = 0; i < n; i++) vis[i] = 0;

    int num = 0;
    reverse(po.begin(), po.end());
    for (int i = 0; i < n; i++) {
        int v = po[i];
        if (!vis[v]) {
            rev_dfs(v, num);
            num++;
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << (id[x] == id[y]) << endl;
    }


}

