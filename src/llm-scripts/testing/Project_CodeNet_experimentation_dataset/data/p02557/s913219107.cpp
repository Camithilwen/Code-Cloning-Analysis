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
    
int n, arr[2][MAXN], l[2][MAXN], r[2][MAXN], ansl, ansr, cnt[MAXN], ans[MAXN];
    
int main() {
    IO::read(n);
    ansr = INT_MAX;
    rep(_, 0, 1) rep(i, 1, n) IO::read(arr[_][i]);
    rep(_, 0, 1) rep(i, 1, n) {
        if (arr[_][i] != arr[_][i - 1]) l[_][arr[_][i]] = i;
        if (arr[_][i] != arr[_][i + 1]) r[_][arr[_][i]] = i;
    }
    rep(i, 1, n) {
        if (l[0][i] && l[1][i]) {
            ansl = max(ansl, r[0][i] - l[1][i] + 1);
            // ansr = min(ansr, abs(l[0][i] - r[1][i]));
            ansr = min(ansr, l[0][i] - r[1][i] + n - 1);
        }
    }
    // printf("l = %d, r = %d\n", ansl, ansr);
    if (ansl > ansr) return puts("No"), 0;
    puts("Yes");
    rep(i, 1, n) {
        ans[(i + ansl - 1) % n + 1] = arr[1][i];
    }
    rep(i, 1, n) printf("%d ", ans[i]);
    return 0;
}