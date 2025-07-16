#include <iostream>
using namespace std;

static const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    long long sum, A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum = (sum + A[i]) % MOD;
    }

    // sum = A1 + A2 + ... + An
    // A1(A2+A3+...+An) + A2(A3+A4+...+An) + ... + An-2(An-1+An) + An-1An
    long long ans = 0;
    for (int i = 0; i < N - 1; i++) {
        sum -= A[i];
        if (sum < 0) sum += MOD;

        ans += A[i] * sum;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}