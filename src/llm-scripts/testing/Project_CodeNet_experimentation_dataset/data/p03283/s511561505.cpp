#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N, M, Q, L, R;
    cin >> N >> M >> Q;
    vector<vector<ll>> sum(N+1, vector<ll>(N+1));
    rep(i,M) {
        cin >> L >> R;
        ++sum[L][R];
    }
    rep(i,N) rep(j,N) sum[i+1][j+1] += sum[i+1][j];
    for (int i = 1; i <= N; ++i) {
        for (int j = N - 1; j > 0; --j) {
            sum[j][i] += sum[j+1][i];
        }
    }

    vector<ll> p(Q), q(Q);
    rep(i,Q) cin >> p[i] >> q[i];

    rep(i,Q) cout << sum[p[i]][q[i]] << endl;
}

