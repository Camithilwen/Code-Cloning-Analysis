#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define SZ(x) ((int)(x).size())
#define PB push_back
template <typename T>
void Puts(T x) {
    cout << x << endl;
}
struct Node {
    vector<int> parents;
    vector<int> children;
    int value;
};
int main() {
    int n, m;
    cin >> n >> m;
    auto nodes = vector<Node>(n, Node{
                                     vector<int>(0),
                                     vector<int>(0),
                                     -1});
    rep(i, n - 1 + m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        nodes[a].children.PB(b);
        nodes[b].parents.PB(a);
    }
    auto current = 0;
    function<void(int)> dfs = [&](auto index) {
        auto &node = nodes[index];
        if (node.value != -1) return;
        for (auto &childIndex : node.children) {
            auto &child = nodes[childIndex];
            if (child.value == -1) {
                dfs(childIndex);
            }
        }
        node.value = current;
        current++;
    };
    rep(i, n) {
        dfs(i);
    };
    rep(i, n) {
        auto &node = nodes[i];
        auto &parents = node.parents;
        if (SZ(parents) == 0) {
            puts("0");
            continue;
        }
        auto minValue = INT_MAX;
        auto ans = 0;
        for (auto &parentIndex : parents) {
            auto &parent = nodes[parentIndex];
            if (parent.value < minValue) {
                ans = parentIndex + 1;
                minValue = parent.value;
            }
        }
        Puts(ans);
    }
}
