#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<int> k(Q);
    rep(i, Q) cin >> k[i];
    rep(i, Q) {
        ll ans = 0;
        vector<ll> D(N + 1, 0), M(N + 1, 0), DM(N + 1, 0);
        rep(j, N) {
            D[j + 1] = D[j];
            M[j + 1] = M[j];
            DM[j + 1] = DM[j];
            if (S[j] == 'D') D[j + 1]++;
            if (j >= k[i] && S[j - k[i]] == 'D') {
                D[j + 1]--;
                DM[j + 1] -= M[j + 1];
            }
            if (S[j] == 'M') {
                M[j + 1]++;
                DM[j + 1] += D[j + 1];
            }
            if (j >= k[i] && S[j - k[i]] == 'M') M[j + 1]--;
            if (S[j] == 'C') ans += DM[j + 1];
            //cout << "j=" << j << " D=" << D[j + 1] << " M=" << M[j + 1] << " DM=" << DM[j + 1] << "\n";
        }
        cout << ans << "\n";
    }
}