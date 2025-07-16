/*
  Contest 104
  B - AcCepted
  Rakesh Kumar --> 27/09/2020
 */

#include <bits/stdc++.h>

bool check_lower(const std::string& s, std::size_t pos) {
    for (std::size_t i = 1; i < s.size(); ++i) {
        if (i != pos && !(s[i] >= 'a' && s[i] <= 'z'))
            return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::string r = "WA";
    if (s[0] == 'A') {
        const std::size_t pos = s.find('C');
        if (pos != std::string::npos) {
            if (pos >= 2 && pos <= s.size() - 2) {
                if (check_lower(s, pos)) {
                    r = "AC";
                }
            }
        }
    }
    std::cout << r << std::endl;

    return 0;
}
