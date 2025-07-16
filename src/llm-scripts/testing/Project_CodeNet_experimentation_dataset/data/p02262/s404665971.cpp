#include <iostream>
#include <utility>
static int isort(long *a, int n, int g) {
    int c = 0;
    for (int i = g; i < n; ++i) {
        long v = a[i];
        int j = i - g;
        for (; j >= 0 && a[j] > v; j -= g, ++c) {
            a[j + g] = a[j];
        }
        a[j + g] = v;
    }
    return c;
}
static int ssort(long *a, int n) {
    int c = 0, m = 1, g[100] = { 1 };
    for (int gm = 3 * g[0] + 1; gm < n; gm = 3 * g[++m - 1] + 1) {
        g[m] = gm;
    }
    std::cout << m << std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout << ((i == 0) ? "" : " ") << g[m - i - 1];
        c += isort(a, n, g[m - i - 1]);
    }
    std::cout << std::endl;
    return c;
}
int main() {
    int n;
    long a[1000000];
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << ssort(a, n) << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << std::endl;
    }
}

