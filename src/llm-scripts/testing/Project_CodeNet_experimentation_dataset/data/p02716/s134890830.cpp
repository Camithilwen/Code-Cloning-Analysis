#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

const Int INF = 1e18;


int main() {
    Int N;
    cin >> N;
    vector<Int> A(N);
    rep(i,N) cin >> A[i];

    vector<Int> dp0(N, -INF), dp1(N, -INF);

    dp0[0] = 0;
    dp1[0] = A[0];
    dp0[1] = max(A[0], A[1]);

    for(int i = 2; i<N; i++) {
        if (i % 2 == 1) {
            dp0[i] = max(dp1[i-1], A[i]+dp0[i-2]);
        }
        else {
            dp0[i] = max(dp0[i-1], A[i] + dp0[i-2]);
            dp1[i] = A[i] + dp1[i-2];
        }
    }

    cout << dp0[N-1] << endl;
}
