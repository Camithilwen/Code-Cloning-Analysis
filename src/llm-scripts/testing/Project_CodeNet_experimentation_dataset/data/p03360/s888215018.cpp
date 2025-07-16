#include "bits/stdc++.h"

using namespace std;

long long dfs(long long K, long long A, long long B, long long C) {
    if (K == 0) {
        return A + B + C;
    }

    long long a = dfs(K - 1, 2 * A, B, C);
    long long b = dfs(K - 1, A, 2 * B, C);
    long long c = dfs(K - 1, A, B, 2 * C);
    return max(max(a, b), c);
}

void Main() {
    long long A, B, C;
    cin >> A >> B >> C;
    long long K;
    cin >> K;

    long long ans = dfs(K, A, B, C);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
