#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

namespace asl
{
    template <typename T>
    using vec = std::vector<T>;

    template <typename T>
    std::istream &operator>>(std::istream &is, std::vector<T> &vec)
    {
        for (auto &value : vec)
            is >> value;
        return is;
    }

    template <typename T>
    struct fenwick
    {
        int n;
        std::vector<T> f;
        fenwick(int n) : n(n), f(n + 1) {}

        T query(int p)
        {
            T ret = 0;
            for (++p; p > 0; p -= p & -p)
                ret += f[p];
            return ret;
        }

        void update(int p, T x)
        {
            for (++p; p <= n; p += p & -p)
                f[p] += x;
        }

    };

    template <typename T>
    using BIT = fenwick<T>;
} 

#include <experimental/optional>

#include <tuple>

namespace asl
{
    typedef long long i64;
    
} 

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

void solve()
{
    int n, q;
    cin >> n >> q;

    vec<int> val(n);
    cin >> val;

    BIT<i64> bit(n);

    for (int i = 0; i < n; ++i)
        bit.update(i, val[i]);

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 0)
        {
            int p, x;
            cin >> p >> x;
            bit.update(p, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << bit.query(r - 1) - bit.query(l - 1) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}


