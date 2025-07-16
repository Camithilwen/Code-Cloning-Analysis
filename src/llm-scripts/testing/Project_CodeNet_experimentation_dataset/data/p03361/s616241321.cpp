#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h+2, vector<char>(w+2));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    int di[] = {1, 0, -1, 0};
    int dj[] = {0, 1, 0, -1};
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if(a[i][j] == '.') {
                continue;
            }
            int x = 0;
            for (int k = 0; k < 4; k++) {
                x += (a[i + di[k]][j + dj[k]] == '#');
            }
           if(!x) {
               cout << "No";
               return;
           }

        }
    }
    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
