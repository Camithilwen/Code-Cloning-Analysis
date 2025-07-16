#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vl k(q);
    for (int i = 0; i < q; ++i) {
        cin >> k[i];
        k[i]--;
    }
    for (int i = 0; i < q; ++i) {
        vl dp(3, 0);
        vl cnt(3, 0);
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'D') {
                dp[0]++;
                cnt[0]++;
            } else if (s[j] == 'M') {
                dp[1] += dp[0];
                cnt[1]++;
            } else if (s[j] == 'C') {
                dp[2] += dp[1];
            }

            if (j >= k[i]) {
                if (s[j - k[i]] == 'D') {
                    dp[0]--;
                    dp[1] -= cnt[1];
                    cnt[0]--;
                } else if (s[j - k[i]] == 'M') {
                    cnt[1]--;
                }
            }
        }
        cout << dp[2] << "\n";
    }
    return 0;
}