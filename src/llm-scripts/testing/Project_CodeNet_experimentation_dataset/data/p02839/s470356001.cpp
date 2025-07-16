#include <bits/stdc++.h>

using namespace std;

using State = pair<pair<int, int>, int>;

int MX = 81*2*81 + 9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    //n = 80; m = 80;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            //a[i][j] = (i+j)%81;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            //v = (81+i-j)%81;
            a[i][j] -= v;
        }
    }
    vector<vector<vector<bool>>> was(n, vector<vector<bool>>(m));
    vector<State> q;
    q.reserve(n*m*MX);
    auto add = [&] (int i, int j, int c) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        auto &vec = was[i][j];
        if (vec.size() == 0) {
            vec.assign(2*MX + 1, false);
        }
        for (int mul = -1; mul <= 1; mul += 2) {
            int nxtC = c + mul*a[i][j];
            int code = nxtC + MX;
            if (!vec[code]) {
                q.push_back({{i, j}, nxtC});
                vec[code] = true;
            }
        }
    };
    add(0, 0, 0);
    int ans = 1e9;
    for (int qi = 0; qi < q.size(); qi++) {
        auto cur = q[qi];
        int i = cur.first.first;
        int j = cur.first.second;
        int c = cur.second;
        if (i == n-1 && j == m-1) {
            ans = min(ans, abs(c));
        }
        add(i+1, j, c);
        add(i, j+1, c);
    }
    cout << ans << endl;
}
