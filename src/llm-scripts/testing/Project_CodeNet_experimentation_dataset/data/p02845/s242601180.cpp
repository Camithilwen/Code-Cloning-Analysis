#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
const long long MOD = 1e9 + 7;

template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int N, A;
    cin >> N;
    ll ans = 1;
    vector<int> cap(3, 0);
    rep(x, N) {
        cin >> A;
        int sam = 0;
        rep(i, 3) if(A == cap[i]) sam++;
        rep(i, 3) {
            if(A == cap[i]) {
                cap[i]++;
                break;
            }
        }
        ans *= sam;
        ans %= MOD;
    }
    cout << ans << endl;
}
