#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, K;
vector<ll> v;
int main() {
    cin >> N >> K;
    v.resize(N);
    rep(i, N) cin >> v[i];

    bool zero_exist = false;
    rep(i, N) {
       if (v[i] == 0) {
           zero_exist = true;
       }
    }

    ll ans = INF;
    if (!zero_exist) {
        v.push_back(0);
        K++;
    }
    sort(v.begin(), v.end());

    ll zero_idx = lower_bound(v.begin(), v.end(), 0) - v.begin();
    // cout << zero_idx << endl;

    for (int i = 0; i <= N + 1 - K; i++) {
        ll r = i + K - 1;
        ll l = i;
        if (l <= zero_idx && zero_idx <= r) {
            ll tmp = INF;
            // 一直線
            if (v[r] < 0) {
                tmp = min(tmp, abs(v[l])); 
            }
            // 一直線
            if (v[l] > 0) {
                tmp = min(tmp, abs(v[r])); 
            }

            // 右行ってから左
            ll dist = abs(v[r]) * 2 + abs(v[l]);
            tmp = min(tmp, dist);

            // 左行ってから右
            ll dist2 = abs(v[l]) * 2 + abs(v[r]);
            tmp = min(tmp, dist2);

            // cout << i << " " << tmp << " " << dist << " " << dist2 << " " << abs(v[l]) << " " << abs(v[r]) << endl;
            ans = min(ans, tmp);
        }
    }
    if (ans == INF) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
}