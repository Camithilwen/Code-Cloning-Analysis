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

void solve() {
    int a, b;
    cin >> a >> b;
    vector<string> res(100);
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (i < 50) res.at(i).push_back('.');
            else res.at(i).push_back('#');
        }
    }
    int x = 0, y = 0;
    for (int i=0; i<b-1; i++) {
        res.at(x).at(y) = '#';
        y += 2;
        if (y >= 100) {
            x += 2;
            y = 0;
        }
    }
    x = 51, y = 0;
    for (int i=0; i<a-1; i++) {
        res.at(x).at(y) = '.';
        y += 2;
        if (y >= 100) {
            x += 2;
            y = 0;
        }
    }
    cout << 100 << ' ' << 100 << '\n';
    for (string s : res) cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
