#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
#include <cstring>
using namespace std;

inline namespace atcoder {
    template <typename T, size_t Depth>
    struct vector_helper { using type = vector<typename vector_helper<T, Depth - 1>::type>; };
    template <typename T>
    struct vector_helper<T, 0> { using type = T; };
    template <typename T, size_t Depth>
    using vector_t = typename vector_helper<T, Depth>::type;

    template <typename T> using vec = vector_t<T, 1>;
    template <typename T> using vvec = vector_t<T, 2>;
    template <typename T> using vvvec = vector_t<T, 3>;
}

int main() {
    int n, m; cin >> n >> m;
    vec<bool> ac(n, false);
    vec<int> wa(n, 0);

    int ans1 = 0, ans2 = 0;
    while (m--) {
        int p; cin >> p; --p;
        char s[3]; cin >> s;
        if (strcmp(s, "AC") == 0) {
            if (!ac[p]) {
                ++ans1;
                ans2 += wa[p];
            }
            ac[p] = true;
        }
        else {
            ++wa[p];
        }
    }

    cout << ans1 << ' ' << ans2 << endl;
}

