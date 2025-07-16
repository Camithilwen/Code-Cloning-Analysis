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

    ll ans = 0;
    for (int l = 0; l <= K; l++) {
        for (int r = 0; r <= K - l; r++) {
            if (l + r > N) continue;

            // 戻せる回数
            int d = K - (l + r);

            vector<ll> calc;
            ll tmp = 0;
            // 左からとる

            // cout << "pat1 l " << l << " r: " << r << " " << tmp << endl;
            // [0, l)
            for (int k = 0; k < l; k++) {
                calc.push_back(v[k]);
                tmp += v[k];
            }

            // 右からとる
            // cout << "pat2 l " << l << " r: " << r << " " << tmp << endl;
            // [N - r, N)
            for (int k = 0; k < r; k++) {
                calc.push_back(v[N - 1 - k]);
                tmp += v[N - 1 - k];
            }

            sort(calc.begin(), calc.end());

            // cout << "pat3 l " << l << " r: " << r << " " << tmp << endl;
            // 戻す
            for (int k = 0; k < min(d, (int)calc.size()); k++) {
                if (calc[k] > 0) break;
                tmp -= calc[k];
            }
            // cout << "l " << l << " r: " << r << " " << tmp << endl;
            ans = max(tmp, ans);
        }
    }

    cout << ans << endl;
}