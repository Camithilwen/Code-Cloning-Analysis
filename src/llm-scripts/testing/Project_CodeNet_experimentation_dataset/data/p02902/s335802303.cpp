//
// Created by Mahmoud Rashad on 11/27/19.
//

#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<ii, ii>> vii;

const int MAXN = 1003;
int vis[MAXN];
int mark[MAXN], checkID;
vector<int> adjList[MAXN];
vector<int> inProgress;
bool ret;


bool check(int x) {
//    cout << x << endl;
    ++checkID;
    mark[x] = checkID;
    inProgress.push_back(x);
    for (int i = (int)inProgress.size() - 2; inProgress[i] != x; --i)
        mark[inProgress[i]] = checkID;
    int i;
    for (i = (int)inProgress.size() - 2; inProgress[i] != x; --i) {
        int u = inProgress[i];
        for (int v : adjList[u]) {
            if (mark[v] == checkID && v != inProgress[i + 1]) {
                inProgress.pop_back();
                return false;
            }
        }
    }
    for (int v : adjList[x]) {
        if (mark[v] == checkID && v != inProgress[i + 1]) {
            inProgress.pop_back();
            return false;
        }
    }
    return true;
}

void dfs(int u) {
    vis[u] = 1;
    inProgress.push_back(u);
    for (int v : adjList[u]) {
        if (vis[v] == 1) {
//            cout << v << endl;
            ret = check(v);
            if (ret)
                return;
        } else if (vis[v] == 0) {
            dfs(v);
            if (ret)
                return;
        }
    }
    inProgress.pop_back();
    vis[u] = 2;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;


    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            if (ret) {
                vector<int> ans;
                for (int i = (int)inProgress.size() - 2; inProgress[i] != inProgress.back(); --i)
                    ans.push_back(inProgress[i]);
                ans.push_back(inProgress.back());
                cout << ans.size() << '\n';
                reverse(ans.begin(), ans.end());
                for (int x : ans)
                    cout << x << '\n';
                return 0;
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}