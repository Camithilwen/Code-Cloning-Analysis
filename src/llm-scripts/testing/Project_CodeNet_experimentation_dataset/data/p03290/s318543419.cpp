#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int D, G; cin >> D >> G;
    vi P(D), C(D); rep(i, D) cin >> P[i] >> C[i];

    int res = INF;
    for (int i = 0; i < 1<<D; i++) {
        vi tmp;
        vi notselected;
        for (int j = 0; j < D; j++) {
            if (i & 1<<j) {
                tmp.push_back(j);
            } else {
                notselected.push_back(j);
            }
        }

        int sum = 0;
        int cnt = 0;
        for (auto ii : tmp) {
            int x = 100 * (ii + 1) * P[ii] + C[ii];
            sum += x;
            cnt += P[ii];
        }
        if (sum >= G) {
            res = min(res, cnt);
            continue;
        }

        sort(notselected.begin(), notselected.end());
        reverse(notselected.begin(), notselected.end());
        int diff = G - sum;
        for (auto ii : notselected) {
            if (diff <= 0) break;
            int x = 100 * (ii + 1) * P[ii] + C[ii];
            if (diff - x > 0) {
                diff -= x;
                cnt += P[ii];
                continue;
            }

            for (int jj = 0; jj < P[ii]; jj++) {
                diff -= 100 * (ii + 1);
                cnt++;
                if (jj == P[ii] - 1) diff -= C[ii];
                if (diff <= 0) break;
            }
        }
        res = min(res, cnt);
    }

    cout << res << endl;
}
