#include <iostream>
#include <vector>
using i64 = long long;

template <class T = long long int>
class Bit {
    private:
    unsigned len;
    T init;
    std::vector<T> arr;

    public:
    Bit(unsigned length, T initialValue = 0): len(length), init(initialValue), arr(len + 1, init) {}
    void update(unsigned a, T newval) {
        for (unsigned x = a; x <= len; x += x & -x) arr[x] += newval;
    }
    T query(unsigned a) const {
        T ret = init;
        for (unsigned x = a; x > 0; x -= x & -x) ret += arr[x];
        return ret;
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;

    Bit<> b(n + 1);
    for (int i = 0; i < n; i++) {
        i64 a;
        std::cin >> a;
        b.update(i + 1, a);
    }

    while (q--) {
        int t, x, y;
        std::cin >> t >> x >> y;
        if (t) std::cout << b.query(y) - b.query(x) << '\n';
        else b.update(x + 1, y);
    }

    return 0;
}
