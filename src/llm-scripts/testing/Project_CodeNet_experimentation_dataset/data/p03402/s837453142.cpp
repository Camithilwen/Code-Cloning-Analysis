#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<bool>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    A--, B--;

    int C = 0, D = 0, W = 0;
    for (int i = 0; i * i < max(A, B); ++i)
        W++;
    W = max(2 * W, 1);

    C = (4 * A + W - 1) / W, D = (4 * B + W - 1) / W;
    C += C & 1, D += D & 1;
    C = max(C + (C & 1), 1), D = max(D + (D & 1), 1);

    printf("%d %d\n", C + D, W);

    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < W; ++j) {
            bool iswhite = (A > 0) & !((i | j) & 1);
            A -= iswhite;
            putchar(iswhite ? '.' : '#');
        }
        putchar('\n');
    }

    for (int i = 0; i < D; ++i) {
        for (int j = 0; j < W; ++j) {
            bool isblack = (B > 0) & (i & j & 1);
            B -= isblack;
            putchar(isblack ? '#' : '.');
        }
        putchar('\n');
    }
    return 0;
}
