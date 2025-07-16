#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()    // 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend() // 降順ソート 例：sort(DESC(vec));
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < n; i++)
#define REP(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)

const int       mod = 1000000007;
const int       inf = (1 << 21);
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T>
inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T>
inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T>
inline T GCD(T a, T b) { return b ? GCD(b, a % b) : a; }
template<class T>
inline T LCM(T a, T b) { return (a + (b - 1)) / b; }
template<class T>
inline T round_int(T a, T b) {return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

int dp[101][9];

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vvi dp(h + 1, vi(w));
    dp[0][0] = 1;

    rep(i, h) {
        rep(j, w) {
            rep(bit, (1 << (w - 1))) {
                bool ok = true;
                
                rep(k, w - 2) {
                    if ((bit >> k) & 1 && (bit >> (k + 1)) & 1) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    if (j >= 1 && ((bit >> (j - 1)) & 1)) {
                        dp[i + 1][j - 1] += dp[i][j];
                        dp[i + 1][j - 1] %= mod;
                    }
                    else if (j <= w - 2 && ((bit >> j) & 1)) {
                        dp[i + 1][j + 1] += dp[i][j];
                        dp[i + 1][j + 1] %= mod;
                    }
                    else {
                        dp[i + 1][j] += dp[i][j];
                        dp[i + 1][j] %= mod;
                    }
                }
            }
        }
    }
    cout << dp[h][k - 1] << endl;
}