#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;

int H, W;
vector<string> grids;
vector<vector<bool>> visited;

Pii link_size(int i, int j) {
    visited[i][j] = true;
    bool color = grids[i][j] == '#';

    Pii ret = Pii(0, 0);
    if (color) ret.first++;
    else ret.second++;

    Pii t;
    if (i > 0 && grids[i][j] != grids[i-1][j] && !visited[i-1][j]) {
        t = link_size(i-1, j); 
        ret.first += t.first; 
        ret.second += t.second;
    }
    if (i < H-1 && grids[i][j] != grids[i+1][j] && !visited[i+1][j]) {
        t = link_size(i+1, j);
        ret.first += t.first; 
        ret.second += t.second;
    }
    if (j > 0 && grids[i][j] != grids[i][j-1] && !visited[i][j-1]) {
        t = link_size(i, j-1);
        ret.first += t.first; 
        ret.second += t.second;
    }
    if (j < W-1 && grids[i][j] != grids[i][j+1] && !visited[i][j+1]) {
        t = link_size(i, j+1);
        ret.first += t.first; 
        ret.second += t.second;
    }
    return ret;
}

int main() {
    cin >> H >> W;
    grids.resize(H);
    for (int i = 0; i < H; i++) cin >> grids[i];
    visited.resize(H);
    for (int i = 0; i < H; i++) visited[i].resize(W);
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) visited[i][j] = false;

    ll ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j]) {
                Pii t = link_size(i, j);
                ans += (ll)t.first * (ll)t.second;
            }
        }
    }
    cout << ans << endl;
}