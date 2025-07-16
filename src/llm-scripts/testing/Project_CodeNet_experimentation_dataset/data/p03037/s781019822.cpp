#include <iostream>

int li, ri, n, m, a, b;

int main() {
    a = 0;
    b = 1000001;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> li >> ri;
        if (li > a) a = li;
        if (b > ri) b = ri;
    }
    int ans = a > b ? 0 : b - a + 1;
    std::cout << ans; 
    return 0;
}