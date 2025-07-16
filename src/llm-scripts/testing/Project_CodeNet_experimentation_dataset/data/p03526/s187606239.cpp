#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
#define whole(x) begin(x), end(x)
using ll = long long;
using namespace std;
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

constexpr ll inf = ll(1e18)+9;
int main() {
    // input
    int n; scanf("%d", &n);
    vector<pair<int, int> > hps(n);
    repeat (i, n) {
        int h, p; scanf("%d%d", &h, &p);
        hps[i] = { h, p };
    }
    // solve
    sort(whole(hps), [&](pair<int, int> hp1, pair<int, int> hp2) {
        return hp1.first + hp1.second < hp2.first + hp2.second;
    });
    vector<ll> dp(n + 1, inf);
    dp[0] = 0;
    for (auto hp : hps) {
        int h, p; tie(h, p) = hp;
        repeat_reverse (j, n) {
            if (dp[j] <= h) {
                setmin(dp[j + 1], dp[j] + p);
            }
        }
    }
    int result = 0;
    repeat (i, n + 1) {
        if (dp[i] < inf) {
            result = i;
        }
    }
    // output
    printf("%d\n", result);
    return 0;
}
