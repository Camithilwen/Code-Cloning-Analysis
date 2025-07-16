#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;
#pragma endregion

std::vector<int> topologicalSort(const Graph &G) {
    int n = (int)G.size();
    std::vector<int> cntIn(n);
    for (auto vec : G) {
        for (int x : vec) {
            cntIn.at(x)++;
        }
    }

    std::vector<int> res;
    std::stack<int> st;
    for (int i=0; i<n; i++) {
        if (cntIn.at(i) == 0) {
            st.push(i);
        }
    }
    while (!st.empty()) {
        int cur = st.top(); st.pop();
        res.push_back(cur);
        for (int x : G.at(cur)) {
            cntIn.at(x)--;
            if (cntIn.at(x) == 0) {
                st.push(x);
            }
        }
    }

    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i=0; i<n+m-1; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a-1).push_back(b-1);
    }

    auto sorted = topologicalSort(G);
    vector<int> res(n, 0);
    for (int x : sorted) {
        for (int nx : G.at(x)) {
            res.at(nx) = x + 1;
        }
    }

    for (int x : res) {
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
