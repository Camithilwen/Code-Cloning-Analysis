#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, long long K) {
    if (N % K == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    solve(N, K);
    return 0;
}
