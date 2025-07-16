#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll sum[3][1000005];
ll combiDM[1000005];

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<int> k(Q);
    rep(i, Q) cin >> k[i];

    rep(j, 3) rep(k, N) sum[j][k] = 0;
    combiDM[0] = 0;

    string T = "DMC";
    rep(i, N) {
        rep(j, 3) {
            if (S[i] == T[j]) ++sum[j][i];
        }
    }

    rep(i, 2) {
        rep(j, N - 1) {
            if (i == 1) {
                combiDM[j + 1] = combiDM[j] + sum[0][j + 1] * sum[1][j + 1];
            }
            sum[i][j + 1] += sum[i][j];
        }
    }

    rep(i, Q) {
        vector<ll> ans(N);
        rep(j, N) {
            if (j < 2) continue;
            ans[j] += ans[j - 1];

            if (sum[2][j] != 1) continue;
            ans[j] += combiDM[j];
            if (j - k[i] < 0) continue;
            ans[j] -= (combiDM[j - k[i]] +
                       sum[0][j - k[i]] * (sum[1][j - 1] - sum[1][j - k[i]]));
        }

        cout << ans[N - 1] << endl;
    }
}