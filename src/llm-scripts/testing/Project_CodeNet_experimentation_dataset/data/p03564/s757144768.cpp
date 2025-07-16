#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    ll N, K;
    cin >> N >> K;
    ll value = 1;
    for (ll i = 0; i < N; ++i) {
        if (value < K) {
            value *= 2;
        } else {
            value += K * (N - i);
            break;
        }
    }
    cout << value << endl;
    return 0;
}