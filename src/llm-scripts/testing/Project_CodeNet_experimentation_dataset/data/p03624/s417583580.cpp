
#include <bits/stdc++.h>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
 
    std::string s;
    std::getline(std::cin, s);
    std::vector<bool> dict(26, false);
    for (char c : s)
        dict[c - 'a'] = true;
    std::string r = "None";
    for (std::size_t i = 0; i < dict.size(); ++i) {
        if (!dict[i]) {
            r = i + 'a';
            break;
        }
    }
    std::cout << r << std::endl;
 
    return 0;
}