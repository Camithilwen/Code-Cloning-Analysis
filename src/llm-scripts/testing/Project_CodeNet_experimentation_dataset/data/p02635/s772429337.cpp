#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int64_t m = s.size();

    vector a(1, 0L);
    int64_t t = 0;
    for (auto c : s) {
        if (c == '0') {
            a.push_back(t);
        } else {
            ++t;
        }
    }
    a.push_back(t);

    int64_t k;
    cin >> k;
    k = min(k, a.back());

    int64_t n = a.size();

    constexpr auto M = 998244353L;

    vector dp(vector(k + 1, vector(a.back() + 1, 0L)));
    int64_t mk = 0;
    dp[0][0] = 1;
    for (auto i : irange(0L, n - 1)) {
        for (auto j : irange(mk, -1L, -1L)) {
            for (auto c : irange(0L, a.back() - a[i + 1] + 1)) {
                for (auto b : irange(c + 1, c + a[i + 1] - a[i] + 1)) {
                    auto w = j + b - c;
                    if (w > k) {
                        break;
                    }
                    mk = max(mk, w);
                    dp[w][c] += dp[j][b];
                    if (dp[w][c] >= M) {
                        dp[w][c] -= M;
                    }
                }
            }

            for (auto c : irange(1L, a.back() - a[i + 1] + 1)) {
                dp[j][c] += dp[j][c - 1];
                if (dp[j][c] >= M) {
                    dp[j][c] -= M;
                }
            }
        }
    }

    int64_t ans = 0;
    for (auto i : irange(0L, k + 1)) {
        ans += dp[i][0];
        if (ans >= M) {
            ans -= M;
        }
    }

    cout << ans << endl;
}
