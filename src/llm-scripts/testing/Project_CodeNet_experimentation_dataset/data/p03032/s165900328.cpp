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
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
const int N = 50, K = 100;
ll mem[N+2][N+1][K+1];
ll opt(int i, int j, int k, vector<int>& v) {
    ll& ans = mem[i+1][j+1][k];
    if(ans == -1) {
        if(i <= j) {
            ans = max({
                k >= 1 ? v[i] + opt(i + 1, j, k - 1, v) : 0,
                k >= 1 ? v[j] + opt(i, j - 1, k - 1, v) : 0,
                k >= 2 ? opt(i + 1, j, k - 2, v) : 0,
                k >= 2 ? opt(i, j - 1, k - 2, v) : 0
            });
        } else {
            ans = 0;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    cin >> v;
    memset(mem, -1, sizeof mem);
    ll ans = 0;
    for(int kk = 0; kk <= k; kk++) {
        ans = max(ans, opt(0, n - 1, kk, v));
    }
    cout << ans << endl;
    return 0;
}
