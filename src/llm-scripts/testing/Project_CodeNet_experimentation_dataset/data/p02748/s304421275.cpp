#include <iostream>
#include <vector>

int main() {
    int A, B, M; std::cin >> A >> B >> M;
    std::vector<int> a(A);
    int ma = 0;
    for (int i = 0; i < A; i++) {
        std::cin >> a[i];
        if (i == 0) {
            ma = a[0];
        } else {
            ma = std::min(ma, a[i]);
        }
    }
    std::vector<int> b(B);
    int mb = 0;
    for (int i = 0; i < B; i++) {
        std::cin >> b[i];
        if (i == 0) {
            mb = b[0];
        } else {
            mb = std::min(mb, b[i]);
        }
    }

    int m = ma + mb;

    for (int i = 0; i < M; i++) {
        int x, y, c; std::cin >> x >> y >> c;
        x--; y--;
        m = std::min(m, a[x] + b[y] - c);
    }
    std::cout << m << std::endl;
    return 0;
}