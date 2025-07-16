#include <bits/stdc++.h>
#define rep(i, n) for (int i{ 0 }; i < n; ++i)

using namespace std;

int main() {
    int d, g;
    cin >> d >> g;
    vector<int> ps(d);
    vector<int> cs(d);

    rep(i, d) cin >> ps[i] >> cs[i];
    // for(auto p :cs) cout <<p;

    int min_cnt{ INT_MAX };
    rep(i, 1 << d) {
        int cnt{ 0 };
        int score{ 0 };
        rep(j, d) if (i >> j & 1) {
            score += ps.at(j) * 100 * (j + 1) + cs.at(j);
            cnt += ps.at(j);
        }
        // cout << "i: " << i << "cnt: " << cnt << "score: " << score << endl;

        for (int j = d - 1; j >= 0; j--) {
            if (score >= g) continue;
            if (i >> j & 1) continue;
            int q = min((int)((g - score) / ((j + 1) * 100)), ps.at(j));
            score += q * 100 * (j + 1);
            cnt += q;
            // cout << "q: " << q << "cnt: " << cnt << "score: " << score << endl;
        }
        // cout << "i: " << i << "cnt: " << cnt << "score: " << score << endl;

        if (score >= g) min_cnt = min(min_cnt, cnt);
    }

    cout << min_cnt << endl;
}
