#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

namespace IO {
    #define gc getchar()
    template <typename T>
    inline void read(T& x) {
        x = 0; bool f = 1; char ch;
        for (ch = gc; ch < '0' || '9' < ch; ch = gc) if (ch == '-') f ^= 1;
        for (; '0' <= ch && ch <= '9'; ch = gc) x = (x << 3) + (x << 1) + (ch ^ 48);
        x = f ? x : -x;
    }
    #undef gc
}

const int MAXN = 2e5 + 10;

int n, arr[2][MAXN], cnt[2][MAXN], val;
vector<int> pos;

int main() {
    IO::read(n);
    rep(_, 0, 1) rep(i, 1, n) IO::read(arr[_][i]), cnt[_][arr[_][i]]++;
    reverse(arr[1] + 1, arr[1] + n + 1);
    rep(i, 1, n) if (arr[0][i] == arr[1][i]) val = arr[0][i], pos.push_back(i);
    int l = 1, r = n; bool flg = false;
    for (auto cur_pos : pos) {
        if (flg == false) {
            if (arr[0][l] != val && arr[1][l] != val) {
                swap(arr[1][l], arr[1][cur_pos]);
                ++l;
            } else flg = true;
        }
        if (flg == true) {
            if (arr[0][r] != val && arr[1][r] != val) {
                swap(arr[1][r], arr[1][cur_pos]);
                --r;
            } else return puts("No"), 0;
        }
    }
    puts("Yes");
    rep(i, 1, n) printf("%d ", arr[1][i]);
    return 0;
}