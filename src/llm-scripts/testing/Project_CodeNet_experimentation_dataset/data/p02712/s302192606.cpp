#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    cin >> N;
    ll sum = 0;
    for (ll i = 1; i <= N; ++i) {
        if (i % 3 == 0) continue;
        if (i % 5 == 0) continue;
        sum += i;
    }
    PR(sum);
    return 0;
}