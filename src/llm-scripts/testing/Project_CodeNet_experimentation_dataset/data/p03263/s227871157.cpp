#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(void) {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> board(H, vector<int>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> board[h][w];
        }
    }

    vector<pair<pair<int, int>, pair<int, int>>> cmds;

    for (int h = 0; h < H; h++) {
        if (h % 2 == 0) {
            for (int w = 0; w < W; w++) {
                int next_h, next_w;
                if (w != W - 1) {
                    next_h = h;
                    next_w = w + 1;
                } else {
                    next_h = h + 1;
                    next_w = w;
                }

                if (next_h >= H) {
                    continue;
                }

                if (board[h][w] % 2 != 0) {
                    board[h][w]--;
                    board[next_h][next_w]++;
                    cmds.push_back(make_pair(make_pair(h, w), make_pair(next_h, next_w)));
                }
            }
        } else {
            for (int w = W - 1; w >= 0; w--) {
                int next_h, next_w;
                if (w != 0) {
                    next_h = h;
                    next_w = w - 1;
                } else {
                    next_h = h + 1;
                    next_w = w;
                }

                if (next_h >= H) {
                    continue;
                }

                if (board[h][w] % 2 != 0) {
                    board[h][w]--;
                    board[next_h][next_w]++;
                    cmds.push_back(make_pair(make_pair(h, w), make_pair(next_h, next_w)));
                }
            }
        }
    }

    cout << cmds.size() << endl;
    for (auto cmd : cmds) {
        pair<int, int> src = cmd.first;
        pair<int, int> dst = cmd.second;
        printf("%d %d %d %d\n", src.first + 1, src.second + 1, dst.first + 1, dst.second + 1);
    }

    return 0;
}
