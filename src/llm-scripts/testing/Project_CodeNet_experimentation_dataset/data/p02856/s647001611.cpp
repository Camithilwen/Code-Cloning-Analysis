#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int M;
    cin >> M;
    ll ans = 0, sum = 0;
    for (int i = 0; i < M; ++i) {
        int d;
        ll c;
        cin >> d >> c;
        sum += d * c;
        ans += c;
    }
    ans += (sum - 1) / 9;

    cout << ans - 1 << endl;
    return 0;
}
