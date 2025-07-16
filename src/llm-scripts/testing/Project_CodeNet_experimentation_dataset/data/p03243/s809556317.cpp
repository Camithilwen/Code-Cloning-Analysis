/*
  Contest 111
  B - AtCoder Beginner Contest 111
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::vector<int> table;
    for (int i = 1; i <= 9; ++i)
        table.emplace_back(i * 111);
    int n = 0;
    std::cin >> n;
    if (n % 111 == 0)
        std::cout << n << std::endl;
    else
        std::cout << table[n / 111] << std::endl;

    return 0;
}
