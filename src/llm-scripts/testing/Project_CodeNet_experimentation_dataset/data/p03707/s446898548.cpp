#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<string> S(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> S[i];
    }
    vector<int> X1(Q), Y1(Q), X2(Q), Y2(Q);
    for ( int i = 0; i < Q; i++ ) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        X1[i]--, Y1[i]--, X2[i]--, Y2[i]--;
    }
    vector<vector<ll>> c(N+1, vector<ll>(M+1));
    for ( int n = 0; n < N; n++ ) {
        for ( int m = 0; m < M; m++ ) {
            if ( S[n][m] == '1' ) c[n+1][m+1] = 1;
        }
    }
    for ( int n = 0; n <= N; n++ ) {
        for ( int m = 0; m < M; m++ ) {
            c[n][m+1] += c[n][m];
        }
    }
    for ( int n = 0; n < N; n++ ) {
        for ( int m = 0; m <= M; m++ ) {
            c[n+1][m] += c[n][m];
        }
    }
    vector<vector<ll>> a(2*N, vector<ll>(2*M));
    for ( int n = 0; n < N; n++ ) {
        for ( int m = 0; m < M-1; m++ ) {
            if ( S[n][m] == '1' && S[n][m+1] == '1' ) a[2*n+1][2*m+2] = 1;
        }
    }
    for ( int n = 0; n < N-1; n++ ) {
        for ( int m = 0; m < M; m++ ) {
            if ( S[n][m] == '1' && S[n+1][m] == '1' ) a[2*n+2][2*m+1] = 1;
        }
    }
    for ( int n = 0; n < 2*N; n++ ) {
        for ( int m = 0; m < 2*M-1; m++ ) {
            a[n][m+1] += a[n][m];
        }
    }
    for ( int n = 0; n < 2*N-1; n++ ) {
        for ( int m = 0; m < 2*M; m++ ) {
            a[n+1][m] += a[n][m];
        }
    }
    for ( int q = 0; q < Q; q++ ) {
        ll x1 = 2*X1[q], y1 = 2*Y1[q];
        ll x2 = 2*X2[q]+1, y2 =2*Y2[q]+1;
        ll j = a[x2][y2] - a[x2][y1] - a[x1][y2] + a[x1][y1];
        ll b = c[X2[q]+1][Y2[q]+1] - c[X2[q]+1][Y1[q]] - c[X1[q]][Y2[q]+1] + c[X1[q]][Y1[q]];
        cout << b - j << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}