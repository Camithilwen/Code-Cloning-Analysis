#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N; cin >> N;
    vector<int64_t> A(N);
    int64_t MOD = 1e9 + 7;
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int64_t sum = 0;
    /* O(N^2)
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (i < j && j <= N) sum += (A.at(i) * A.at(j)) % MOD;
        }
    }
    */
  
    vector<int64_t> B(N + 1);
    for (int i = 0; i < N; i++) B.at(i + 1) = (B.at(i) + A.at(i)) % MOD;

    int64_t ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += A.at(i) * (B.at(N) - B.at(i + 1) + MOD);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}