#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    K = min(K, 50);
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    while (K-- > 0) {
        vector<int> B(N + 1);
        REP(i, N) {
            B[max(i - A[i], 0)] += 1;
            B[min(i + A[i] + 1, N)] -= 1;
        }
        REP(i, N) {
            B[i + 1] += B[i];
        }
        A = B;
    }

    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
