#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define vl vector<ll>

int main() {

    ll D, G;
    cin >> D >> G;

    vl p(D), c(D);
    rep(i, D) cin >> p[i] >> c[i];

    int ans = 1e9;
    rep(i, 1<<D) {
        vl P = p;
        int prob = 0;
        ll score = 0;
        rep(j, D) {
            if (i>>j&1) {
                score += ((j+1) * 100 * P[j]);
                score += c[j];
                prob += P[j];
                P[j] = 0;
            }
        }
        int itr = D-1;
        bool ok = true;
        while(score < G) {
            while (P[itr] < 1) {
                itr--;
                if (itr < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                score += ((itr+1)*100);
                prob++;
                P[itr]--;
            }
            else break;
        }

        if (ok) ans = min(prob, ans);
        // cout << "i: " << i << "  score: " << score << "  prob: " << prob << endl;
        // rep(j, D) cout << (j+1)*100 << ": " << p[j] - P[j] << endl;
    }

    cout << ans << endl;

    return 0;
}
