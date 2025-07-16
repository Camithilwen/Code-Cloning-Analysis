#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> x;
    rep(i, N) {
        ll a;
        cin >> a;
        if (a == 0) {
            K--;
            N--;
        } else
            x.push_back(a);
    }

    if (x.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int a = lower_bound(all(x), 0) - x.begin();
    ll ans = INF;
    int s = a - K, t = a - 1;
    int cnt = 0;
    while (cnt <= K) {
        if (s < 0 || t >= N) {
            cnt++;
            s++;
            t++;
            continue;
        } else if (x[s] * x[t] < 0) {
            ans = min(ans, abs(x[s] * 2) + abs(x[t]));
            ans = min(ans, abs(x[s]) + abs(x[t] * 2));
        } else
            ans = min(ans, max(abs(x[s]), abs(x[t])));
        cnt++;
        s++;
        t++;
    }

    cout << ans << endl;
    return 0;
}