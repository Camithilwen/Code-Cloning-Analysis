#include <iostream>
#include <vector>
#include <algorithm>

long long solve(int n, const std::vector<long long> & a, const std::vector<long long> & b, const std::vector<long long> & c) {
    long long res { 0LL };
    
    for (int i = 0; i < n; ++i) {
        const long long m { b[i] };
        const long long an { std::distance(a.begin(), std::lower_bound(a.begin(), a.end(), m)) };
        const long long cn { std::distance(c.begin(), std::upper_bound(c.begin(), c.end(), m)) };
        res += (an * (n - cn));
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    std::vector<long long> a;
    for (int i = 0; i < n; ++i) {
        long long ai;
        std::cin >> ai;
        a.push_back(ai);
    }
    std::sort(a.begin(), a.end());
    
    std::vector<long long> b;
    for (int i = 0; i < n; ++i) {
        long long bi;
        std::cin >> bi;
        b.push_back(bi);
    }
    std::sort(b.begin(), b.end());

    std::vector<long long> c;
    for (int i = 0; i < n; ++i) {
        long long ci;
        std::cin >> ci;
        c.push_back(ci);
    }
    std::sort(c.begin(), c.end());
    
    std::cout << solve(n, a, b, c) << std::endl;
    
    return 0;
}
