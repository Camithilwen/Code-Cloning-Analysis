#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#define bit(n, k) ((n) >> (k) & 1)
const int MOD = (int)1e9 + 7;
template<class T> void add(T &a, T b) { (a += (b % MOD + MOD) % MOD) %= MOD; }

int main() {
    int h, w; cin >> h >> w;
    int K; cin >> K; K--;
    vector<vector<int>> num(w, vector<int>(w));
    for (int mask = 0; mask < 1 << (w - 1); mask++) {
        bool ok = true;
        for (int i = 0; i + 1 < w - 1; i++) {
            if (bit(mask, i) && bit(mask, i + 1)) ok = false;
        }
        if (!ok) continue;
        vector<int> p(w);
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < w - 1; i++) if (bit(mask, i)) swap(p[i], p[i + 1]);
        for (int i = 0; i < w; i++) num[i][p[i]]++;
    }
    vector<vector<long long>> dp(h + 1, vector<long long>(w));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) for (int k = 0; k < w; k++) {
            add(dp[i + 1][k], dp[i][j] * num[j][k]);
        }
    }
    cout << dp[h][K] << endl;
    return 0;
}
