#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>
 
 
int main() {
    std::string s; std::cin >> s;
    int n = s.size();
    if (n & 1) {
        std::cout << "No" << std::endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i += 2) {
        if (s[i] != 'h' || s[i + 1] != 'i') {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}