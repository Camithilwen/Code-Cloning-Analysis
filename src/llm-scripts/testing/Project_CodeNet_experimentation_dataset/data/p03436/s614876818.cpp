#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int H, W;

bool check(int i, int j, int dx, int dy, vector<vector<int>> &field) {
    int x = i + dx;
    int y = j + dy;
    return (x >= 0 && x < H && y >= 0 && y < W && (field[x][y] == -1));
}

int main() {
    cin >> H >> W;
    vector<vector<int>> field(H, vector<int>(W));
    int white = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            if (c == '.') {
                field[i][j] = -1;
                white++;
            }
            else field[i][j] = -2;
        }
    }
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    field[0][0] = 0;
    queue<pii> que;
    que.push({0, 0});
    while (!que.empty()) {
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        if (i == (H - 1) && j == (W - 1)) {
            cout << white - field[H-1][W-1] - 1 << endl;
            return 0;
        }
        for (int k = 0; k < 4; k++) {
            if (check(i, j, dx[k], dy[k], field)) {
                que.push({i + dx[k], j + dy[k]});
                field[i + dx[k]][j + dy[k]] = field[i][j] + 1;
            }
        }
    }
    cout << -1 << endl;
}