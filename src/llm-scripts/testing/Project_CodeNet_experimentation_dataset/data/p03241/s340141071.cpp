#include <bits/stdc++.h>
using namespace std;

int max_gcd(int n, int m) {
    if (n == 1) return m;
    for (int gcd = m / n; gcd > 0; --gcd) {
        if (m % (gcd * n) % gcd == 0) return gcd;
    }
    return 1;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::cout << max_gcd(N, M) << '\n';
    return 0;
}