#include <bits/stdc++.h>
using namespace std;
int main(){
    int H, W, B = 0;
    cin >> H >> W;
    vector<int> color(H * W);
    vector<vector<int>> grid(H * W);
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < W; j++) {
            color.at(i * W + j) = S.at(j);
            if (S.at(j) == '#') {
                B++;
            }
        }
    }
    for (int i = 0; i < H * W; i++) {
        if (color.at(i) == '#') {
            continue;
        }
        if (i >= W) {
            if (color.at(i - W) == '.') {
                grid.at(i).push_back(i - W);
            }
        }
        if (i < W * (H - 1)) {
            if (color.at(i + W) == '.') {
                grid.at(i).push_back(i + W);
            }
        }
        if (i % W != 0) {
            if (color.at(i - 1) == '.') {
                grid.at(i).push_back(i - 1);
            }
        }
        if (i % W != W - 1) {
            if (color.at(i + 1) == '.') {
                grid.at(i).push_back(i + 1);
            }
        }
    }
    vector<int> dist(H * W,-1);
    queue<int> que;
    que.push(0);
    dist.at(0) = 0;
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < (int) grid.at(v).size(); i++){
            int nv = grid.at(v).at(i);
            if (dist.at(nv) != -1 && dist.at(nv) <= dist.at(v) + 1) {
                continue;
            }
            dist.at(nv) = dist.at(v) + 1;
            que.push(nv);
        }    
    }
    if (dist.at(H * W - 1) != -1) {
        cout << H * W - B - 1 - dist.at(H * W - 1) << endl;
    }
    else {
        cout << -1 << endl;
    }
}