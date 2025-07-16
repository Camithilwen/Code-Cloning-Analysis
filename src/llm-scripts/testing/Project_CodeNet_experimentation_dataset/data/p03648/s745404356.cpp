#include <bits/stdc++.h>

int main() {
    long long k;
    std::cin >> k;
    std::cout << 50 << std::endl;
    const auto p = k / 50 + 50, q = p - 1 - (k % 50);
    for (int i = 0; i < k % 50; i++) {
        std::cout << p << " ";
    }
    for (int i = k % 50; i < 50; i++) {
        std::cout << q << " ";
    }
    std::cout << std::endl;

    return 0;
}