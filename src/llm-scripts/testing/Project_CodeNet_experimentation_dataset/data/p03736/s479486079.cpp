#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, a, b; 
    scanf("%d%d%d%d", &n, &q, &a, &b);
    a--, b--;
    vector<int> x(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &x[i]);
        x[i]--;
    }
    constexpr int64_t kInf = 1'000'000'000'000'000'000;
    vector<int64_t> dp(n, kInf);
    vector<int64_t> pref(n + 1, kInf), suff(n + 1, kInf);

    auto Modify = [&](int p, int64_t v, vector<int64_t> &fw) {
        for (int i = p + 1; i <= n; i += i & -i) fw[i] = min(fw[i], v); 
    };

    auto Query = [&](int p, const vector<int64_t> &fw) {
        int64_t res = kInf;
        for (int i = p + 1; i > 0; i -= i & -i) res = min(res, fw[i]);
        return res;
    };

    int64_t sum = 0;
    dp[a] = 0;
    Modify(a, -a, pref);
    Modify(n - 1 - a, a, suff);
    for (int i = 0, v = b; i < q; ++i) {
        int64_t res = min(Query(x[i], pref) + x[i], Query(n - 1 - x[i], suff) - x[i]) + sum;
        sum += abs(x[i] - v);
        dp[v] = min(dp[v], res - sum);
        Modify(v, dp[v] - v, pref);
        Modify(n - 1 - v, dp[v] + v, suff);
        v = x[i];
    }
    int64_t ans = *min_element(dp.begin(), dp.end()) + sum;
    cout << ans << "\n";
    return 0;
}
