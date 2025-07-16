#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;



int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, K;
    cin >> n >> m >> K;

    if (m == 1) {
        if (K == 1) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return 0;
    }

    const long long MOD = 1000000007;

    int M = 1 << (m - 1);

    vector<long long> dp(m, 0);
    dp[0] = 1;
    auto ndp = dp;

    vector<vector<long long>> cnts(m, vector<long long>(3, 0));
    int total = 0;
    for (int i = 0; i < M; ++i) {
        if (i & (i >> 1)) {
            continue;
        }
        ++total;

        for (int j = 0; j < m - 1; ++j) {
            if (i & (1 << j)) {
                cnts[j + 1][0] += 1;
                cnts[j][2] += 1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cnts[i][1] = total - cnts[i][0] - cnts[i][2];
    }

    for (int _ = 0; _ < n; ++_) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int i = 0; i < m; ++i) {
            for (int j = -1, k = 0; k <= 2; ++k, ++j) {
                int ni = i + j;
                if (ni >= 0 && ni < m) {
                    (ndp[ni] += (dp[i] * cnts[i][k]) % MOD) %= MOD;
                }
            }
        }
        swap(ndp, dp);
    }

    cout << dp[K - 1] << '\n';

    return 0;
}