/*
  Contest 091
  B - Two Colors Card Game
  Rakesh Kumar --> 21/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::unordered_map<std::string, int> dict;
    int n = 0;
    std::cin >> n;
    std::cin.ignore();
    while (n--) {
        std::string s;
        std::getline(std::cin, s);
        ++dict[s];
    }
    std::cin >> n;
    std::cin.ignore();
    while (n--) {
        std::string s;
        std::getline(std::cin, s);
        --dict[s];
    }

    int max = 0;
    for (auto it : dict)
        max = std::max(max, it.second);
    std::cout << max << std::endl;

    return 0;
}
