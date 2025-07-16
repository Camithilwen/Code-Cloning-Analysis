// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A&lang=ja
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)

// 盤面の縦横サイズ
const int SZ = 8;

// クイーンが配置可能かチェック
bool check(int row, int col, map<int, int> mp) {
    bool ret = true;
    REP(i, SZ) {
        // 左上, 右上
        if (mp.find(row - i) != mp.end()) {
            int t = mp[row - i];
            if (t == col - i || t == col + i) {
                ret = false;
                break;
            }
        }
        // 左下, 右下
        if (mp.find(row + i) != mp.end()) {
            int t = mp[row + i];
            if (t == col - i || t == col + i) {
                ret = false;
                break;
            }
        }
        // 列
        if (mp.find(i) != mp.end()) {
            int t = mp[i];
            if (t == col || t == col) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

// 深さ優先探索で配置可能な場所を探す。引数は行、配置済みのmap<行,列>
// 答えを出力したらtrueを返す。
bool dfs(int row, map<int, int> mp) {
    // クイーンを8行配置した
    if (row == SZ) {
        // 正解パターンを出力
        REP(row, SZ) {
            // Queenが存在する列
            int t = mp[row];
            REP(col, t) { cout << "."; }
            cout << "Q";
            FOR(col, t + 1, SZ) { cout << "."; }
            cout << "\n";
        }
        return true;
    }
    // その行にQueenが存在しなければ追加
    if (mp.count(row) == 0) {
        REP(col, SZ) {
            if (check(row, col, mp)) {
                mp[row] = col;
                if (dfs(row + 1, mp)) {
                    return true;
                }
            }
        }
    } else {
        if (dfs(row + 1, mp)) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int N;
    cin >> N;
    map<int, int> mp;
    REP(i, N) {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    dfs(0, mp);
    return 0;
}
