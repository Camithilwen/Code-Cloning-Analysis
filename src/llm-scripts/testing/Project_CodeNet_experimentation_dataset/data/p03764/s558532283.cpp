#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
const int M = 1'000'000'007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    cin >> x >> y;
    adjacent_difference(x.begin(), x.end(), x.begin());
    adjacent_difference(y.begin(), y.end(), y.begin());
    ll ysum = 0;
    for(int j = 1; j < m; j++) {
        ysum += y[j] * (m - j) % M * j % M;
        ysum %= M;
    }
    ll xsum = 0;
    for(int i = 1; i < n; i++) {
        xsum += x[i] * (n - i) % M * i % M;
        xsum %= M;
    }
    cout << xsum * ysum % M << endl;
    return 0;
}
