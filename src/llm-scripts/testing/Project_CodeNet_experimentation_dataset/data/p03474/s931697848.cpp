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
    ll A, B;
    cin >> A >> B;
    string str;
    cin >> str;

    bool isOk = true;
    REP(i, str.size()) {
        if (i == A) {
            isOk &= str[i] == '-';
        } else {
            isOk &= str[i] != '-';
        }
        if (!isOk) break;
    }
    PR(isOk ? "Yes" : "No");
    return 0;
}