#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int n = 0, m = 0;
vector<vector<int>> g;
vector<bool> vi;
vector<int> comp;
stack<int> post;
vector<pair<int, int>> q;
void input() {
    cin >> n >> m;
    g = vector<vector<int>>(n, vector<int>());
    vi = vector<bool>(n, false);
    comp = vector<int>(n, -1);
    q = vector<pair<int, int>>(0);
    while (m--) {
        int a = 0, b = 0;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int Q = 0;
    cin >> Q;

    while (Q--) {
        int q1 = 0, q2 = 0;
        cin >> q1 >> q2;
        q.push_back({q1, q2});
    }
}

void dfs1(int i) {
    vi[i] = true;
    for (auto nig : g[i]) {
        if (vi[nig] == false) {
            dfs1(nig);
        }
    }
    post.push(i);
}
void reverseG() {
    vector<vector<int>> rev(n, vector<int>(0));
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int node = g[i][j];
            rev[node].push_back(i);
        }
    }
    g = rev;
}
void dfs2(int i, int comp_n) {
    comp[i] = comp_n;
    for (auto nig : g[i]) {
        if (comp[nig] == -1) {
            dfs2(nig, comp_n);
        }
    }
}
void compute() {
    for (int i = 0; i < n; i++) {
        if (vi[i] == false) dfs1(i);
    }
    reverseG();
    int comp_n = 0;
    while (!post.empty()) {
        int curr = post.top();
        post.pop();
        if (comp[curr] == -1) dfs2(curr, ++comp_n);
    }
    for (auto qq : q) {
        if (comp[qq.first] == comp[qq.second])
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
}

int main() {
    input();
    compute();
    return 0;
}
