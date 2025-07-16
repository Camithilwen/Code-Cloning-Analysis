#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    long long n, m, result = 0;
    cin >> n >> m;
    long long x[n], y[m];
    for (long long i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (long long i = 0; i < m; i++) {
        cin >> y[i];
    }
    long long left = 0, right = 0;
    for (long long i = 1, prefix = y[0]; i < m; i++) {
        left = (left + MOD - prefix + i * y[i]) % MOD;
        prefix = (prefix + y[i]) % MOD;
    }
    for (long long i = 1, prefix = x[0]; i < n; i++) {
        right = (right + MOD - prefix + i * x[i]) % MOD;
        prefix = (prefix + x[i]) % MOD;
    }
    cout << (left * right) % MOD;
    return 0;
}