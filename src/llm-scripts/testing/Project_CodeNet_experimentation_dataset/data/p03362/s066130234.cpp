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
    int n; std::cin >> n;
    bool used[1000000] = {};
    std::vector<int> ans;
    for (int i = 2; i <= 55555; i++) {
        if (used[i]) continue;
        if (i % 5 == 1) ans.push_back(i);
        int w = i;
        while (w <= 555555) {
            used[w] = true;
            w += i;
        }
    }
    for (int i = 0; i < n; i++) std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}
