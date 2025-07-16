#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    ll N, Q;
    cin >> N >> Q;
    
    string S;
    cin >> S;

    vector<ll> F(N + 1), B(N + 1);
    ll tmp = 0, total;

    rep(i, N - 1) {
        if (S[i] == 'A' && S[i + 1] == 'C') {
            tmp++;
        }
        F[i + 2] = tmp;
    }

    total = tmp;
    tmp = 0;

    for (ll i = N - 1; i >= 1; i--) {
        if (S[i - 1] == 'A' && S[i] == 'C') {
            tmp++;
        }
        B[i] = tmp;
    }

    vector<ll> ans(Q);
    ll x, y;

    rep(i, Q) {
        cin >> x >> y;
        ans[i] = total - B[y] - F[x];
    }

    rep(i, Q) {
        cout << ans[i] << endl;
    }

    return 0;
}
