#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int vis[N] , n;

bool cycle(int node , int lim) {
    if (vis[node])
        return vis[node] == 1;

    if (!lim)
        return 0;

    vis[node] = 1;
    for (int c : adj[node])
        if (cycle(c , lim - 1))
            return 1;
    vis[node] = 2;

    return 0;
}

vector<int> sec;
void find_ans(int node , int lim) {
    if (vis[node] == 2)
        return;

    if (vis[node] == 1) {
        for (int c : sec)
            cout << c << '\n';
        exit(0);
    }

    if (!lim)
        return;

    sec.push_back(node);
    vis[node] = 1;

    for (int c : adj[node])
        find_ans(c , lim - 1);

    vis[node] = 2;
    sec.pop_back();
}

bool good(int lim) {
    for (int st = 1 ; st <= n ; st++) {
        memset(vis , 0 , sizeof vis);
        if (cycle(st , lim))
            return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int m;
    cin >> n >> m;

    while (m--) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int l = 2 , r = n , ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
    if (~ans) {
        cout << '\n';
        for (int st = 1 ; st <= n ; st++) {
            memset(vis , 0 , sizeof vis);
            if (cycle(st , ans)) {
                memset(vis , 0 , sizeof vis);
                find_ans(st , ans);
                return 0;
            }
        }
    }
}
