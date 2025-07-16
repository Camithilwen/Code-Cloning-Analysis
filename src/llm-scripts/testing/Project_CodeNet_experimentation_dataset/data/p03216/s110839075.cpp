#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<int> k(Q);
    rep(i, Q) cin >> k[i];
    vector<ll> Dsum(N + 1, 0), Msum(N + 1, 0), DM(N + 1, 0);
    rep(i, N) {
        Dsum[i + 1] = Dsum[i];
        if (S[i] == 'D') Dsum[i + 1]++;
        Msum[i + 1] = Msum[i];
        if (S[i] == 'M') Msum[i + 1]++;
    }
    rep(i, Q) {
        ll ans = 0, DM = 0;
        rep(j, N) {
            int j0 = j - k[i];
            if (j0 >= 0 && S[j0] == 'D') DM -= Msum[j + 1] - Msum[j0];
            if (S[j] == 'M') DM += Dsum[j] - Dsum[max(0, j0)];
            if (S[j] == 'C') ans += DM;
        }
        cout << ans << endl;
    }
}