#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^8 -> 8回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    auto dist = [&](int i, int j) {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        return sqrt(dx * dx + dy * dy);
    };
    vector<int> p(n);
    rep(i, n) p.at(i) = i;
    double len = 0;
    int cnt = 0;
    do {
        rep(i, n - 1) {
            len += dist(p.at(i), p.at(i + 1));
        }
        cnt++;
    } while (next_permutation(p.begin(), p.end()));
    double ans = len / cnt;
    printf("%.10f\n", ans);

    return 0;
}
