#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MAX_LEN = 200000;
set<int64_t> up[MAX_LEN + 1], right_st[MAX_LEN + 1], down[MAX_LEN + 1], left_st[MAX_LEN + 1];
set<int64_t> downs[MAX_LEN * 2 + 1], lefts[MAX_LEN * 2 + 1];

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> X(N), Y(N), dir_num(N);
    vector<char> U(N);

    map<char, int64_t> dirChar2dirNum = {
            { 'U', 0 },
            { 'R', 1 },
            { 'D', 2 },
            { 'L', 3 }
    };

    for (int64_t i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> U[i];
        dir_num[i] = dirChar2dirNum[U[i]];
    }

    int64_t ans = LLONG_MAX;

    //まず正面衝突があるか調べる
    for (int64_t i = 0; i < N; i++) {
        if (U[i] == 'U') {
            up[X[i]].insert(Y[i]);
        } else if (U[i] == 'R') {
            right_st[Y[i]].insert(X[i]);
        } else if (U[i] == 'D') {
            down[X[i]].insert(Y[i]);
        } else if (U[i] == 'L') {
            left_st[Y[i]].insert(X[i]);
        }
    }

    //下向きの一番大きい位置と,上向きの一番小さい位置を比べて交差するかを検証
    for (int64_t x = 0; x <= MAX_LEN; x++) {
        if (down[x].empty() || up[x].empty()) {
            continue;
        }

        for (int64_t up_p : up[x]) {
            //これより大きいのがあれば一番近いやつを見る
            auto itr = down[x].lower_bound(up_p);
            if (itr != down[x].end()) {
                ans = min(ans, 5 * (*itr - up_p));
            }
        }
    }

    for (int64_t y = 0; y <= MAX_LEN; y++) {
        if (left_st[y].empty() || right_st[y].empty()) {
            continue;
        }

        for (int64_t right_p : right_st[y]) {
            auto itr = left_st[y].lower_bound(right_p);
            if (itr != left_st[y].end()) {
                ans = min(ans, 5 * (*itr - right_p));
            }
        }
    }
    
    //90度での衝突を調べる
    for (int64_t j = 0; j < 4; j++) {
        //downとleftの衝突だけを調べる
        //x + yが一致しているものがぶつかりそう
        for (int64_t xy = 0; xy <= MAX_LEN * 2; xy++) {
            downs[xy].clear();
            lefts[xy].clear();
        }

        for (int64_t i = 0; i < N; i++) {
            if (dir_num[i] == dirChar2dirNum['D']) {
                downs[X[i] + Y[i]].insert(Y[i]);
            } else if (dir_num[i] == dirChar2dirNum['L']) {
                lefts[X[i] + Y[i]].insert(Y[i]);
            }
        }

        //
        for (int64_t xy = 0; xy <= MAX_LEN * 2; xy++) {
            for (int64_t left_p : lefts[xy]) {
                auto itr = downs[xy].lower_bound(left_p);
                if (itr != downs[xy].end()) {
                    ans = min(ans, 10 * (*itr - left_p));
                }
            }
        }

        //90度回転
        for (uint64_t i = 0; i < X.size(); i++) {
            swap(X[i], Y[i]);
            Y[i] = MAX_LEN - Y[i];
            (++dir_num[i]) %= 4;
        }
    }

    if (ans == LLONG_MAX) {
        cout << "SAFE" << endl;
    } else {
        cout << ans << endl;
    }
}