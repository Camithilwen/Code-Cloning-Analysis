/*
  Contest 096
  B - Maximum Sum
  Rakesh Kumar --> 23/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    int k = 0;
    std::cin >> k;
    int v = std::max(std::max(a, b), c);
    int total = a + b + c - v;
    while (k--) {
        v <<= 1;
    }
    total += v;
    std::cout << total << std::endl;

    return 0;
}
