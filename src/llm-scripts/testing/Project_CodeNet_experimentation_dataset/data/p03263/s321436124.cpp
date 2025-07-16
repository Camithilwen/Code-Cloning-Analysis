#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MX = 500;

int h, w;
int grid[MX][MX];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool valid(int x, int y) {
    return (x >= 0 && x < h && y >= 0 && y < w);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<pair<int, int>> starts, ends;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!grid[i][j]) continue;
            int fx = -1, fy = -1;
            bool set = false;
            for (int k = 0; k < 4; k++) {
                int a = i + dx[k], b = j + dy[k];
                if (!valid(a, b)) continue;
                if (grid[i][j] % 2 != grid[a][b] % 2) {
                    if (grid[i][j] % 2) fx = a, fy = b;
                } else if (grid[i][j] % 2 == 0 && grid[a][b] % 2 == 0) {
                    continue;
                } else {
                    starts.push_back({i, j});
                    ends.push_back({a, b});
                    grid[a][b]++;
                    grid[i][j]--;
                    set = true;
                    break;
                }
            }
            if (fx != -1 && !set) {
                starts.push_back({i, j});
                ends.push_back({fx, fy});
                grid[fx][fy]++;
                grid[i][j]--;
            }
        }
    }
    
    cout << starts.size() << '\n';
    for (int i = 0; i < (int)starts.size(); i++) {
        cout << starts[i].first + 1 << ' ' << starts[i].second + 1 << ' ' << ends[i].first + 1 << ' ' << ends[i].second + 1 << '\n';
    }
}

