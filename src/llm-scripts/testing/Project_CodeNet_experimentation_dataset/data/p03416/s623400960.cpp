/*
  Contest 090
  A - Diagonal String
  Rakesh Kumar --> 18/09/2020
 */

#include <bits/stdc++.h>

inline bool palindrome(const std::string& s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int a = 0, b = 0;
    std::cin >> a >> b;

    int count = 0;
    for (int n = a; n <= b; ++n)
        if (palindrome(std::to_string(n)))
            ++count;
    std::cout << count << std::endl;

    return 0;
}
