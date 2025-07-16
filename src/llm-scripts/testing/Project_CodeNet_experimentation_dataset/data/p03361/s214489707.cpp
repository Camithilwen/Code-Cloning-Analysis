#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    char s[h][w];
    rep(i, h) rep(j, w) cin >> s[i][j];

    rep(i, h) rep(j, w) {
        if (s[i][j] == '.') continue;
        bool ok = false;
        for (int y = -1; y <= 1; y += 2) {
            int dy = i + y;
            if (dy >= 0 && dy < h && s[dy][j] == '#') ok = true;
        }
        for (int x = -1; x <= 1; x += 2) {
            int dx = j + x;
            if (dx >= 0 && dx < w && s[i][dx] == '#') ok = true;
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
