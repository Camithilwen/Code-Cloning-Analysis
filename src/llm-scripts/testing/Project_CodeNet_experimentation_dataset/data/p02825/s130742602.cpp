#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1個置くと3増えて全体でN*Q
// クオリティQは3の倍数になる必要がある(N != 0 mod 3)

using block = vector<string>;
// Quality 1
block b3 = {
        "a..",
        "a..",
        ".aa"
};
// Quality 3
block b4 = {
        "aacd",
        "bbcd",
        "cdaa",
        "cdbb"
};
// Quality 3
block b5 = {
        "aabbc",
        "bc..c",
        "bc..d",
        "c.ccd",
        "cddee"
};
// Quality 3
block b7 = {
        "ac..c..",
        "ac..c..",
        "b.cc.cc",
        "bc..c..",
        "ac..c..",
        "a.cc.cc",
        ".aabbaa"
};

void horizontal_add(block &a, block b){
    for (int i = 0; i < a.size(); ++i) a[i] += b[i];
}

void vertical_add(block &a, block b){
    a.insert(a.end(), b.begin(), b.end());
}

block solve_k(int n, block b){
    block res = b;
    for (int i = 0; i < n - 1; ++i) {
        horizontal_add(res, b);
    }
    block unit = res;
    for (int i = 0; i < n - 1; ++i) {
        vertical_add(res, unit);
    }
    return res;
}

block solve(int n){
    block res;
    if (n % 3 == 0) return solve_k(n/3, b3);
    if (n % 4 == 0) return solve_k(n/4, b4);
    int t = __builtin_ctz(n);
    int m = n >> t; // m >= 5 が保証される
    if ((m - 1) % 4) res = b7;
    else res = b5;
    for (int i = 0; i < (m - 5) / 4; ++i) {
        horizontal_add(res, block(res.size(), "...."));
        string s(res.size(), '.');
        block below(4, s);
        horizontal_add(below, b4);
        vertical_add(res, below);
    }
    return solve_k(n/m, res);
}

int main() {
    int N;
    cin >> N;
    if (N == 2) {
        cout << -1 << "\n";
    } else {
        auto ans = solve(N);
        for (int i = 0; i < N; ++i) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}