#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
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

namespace asl
{
    
    template <typename T>
    std::vector<std::vector<T>> board(int n = 0, int m = 0)
    {
        return std::vector<std::vector<T>>(n, std::vector<T>(m));
    }

} 

namespace asl
{
    
    const int m1000000007 = 1000000007;
    
    const int m998244353 = 998244353;

    int MOD = m1000000007;

    void set_mod(int mod)
    {
        MOD = mod;
    }

    class Mint
    {
    public:
        int val;

        Mint(long long v = 0)
        {
            if (v >= 0)
            {
                if (v < MOD)
                    val = v;
                else
                    val = v % MOD;
            }
            else
            {
                if (v >= -MOD)
                {
                    val = v + MOD;
                }
                else
                {
                    v %= MOD;
                    if (v < 0)
                        v += MOD;
                    val = v;
                }
            }
        }

        Mint &operator+=(const Mint &other)
        {
            val += other.val;
            if (val >= MOD)
                val -= MOD;
            return *this;
        }

        Mint &operator-=(const Mint &other)
        {
            val -= other.val;
            if (val < 0)
                val += MOD;
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &stream, const Mint &m)
        {
            return stream << m.val;
        }

    };
} 

#include <random>

#define endl '\n'

using namespace std;
using namespace asl;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set_mod(m998244353);

    string s;
    int k;

    cin >> s >> k;

    s += "0";

    vector<int> g;
    int total = 0;
    int ones = 0;

    for (auto x : s)
    {
        if (x == '1')
        {
            ++total;
            ++ones;
        }
        else
        {
            g.push_back(total);
            total = 0;
        }
    }

    reverse(g.begin(), g.end());

    auto dp = board<Mint>(ones + 1, ones + 1);

    dp[0][0] = 1;

    for (int i = 0; i < g.size(); ++i)
    {
        auto ndp = board<Mint>(ones + 1, ones + 1);

        for (int k = 0; k <= ones; ++k)
        {
            for (int l = 0; l <= ones; ++l)
            {
                if (l > 0 && k > 0)
                    ndp[l][k] = ndp[l - 1][k - 1];

                int rmin = l - g[i] - 1; 
                if (rmin >= 0 && k - l + rmin >= 0)
                    ndp[l][k] -= dp[rmin][k - l + rmin];

                int rmax = l - 1; 
                if (rmax >= 0 && k - l + rmax >= 0)
                    ndp[l][k] += dp[rmax][k - l + rmax];
            }
        }

        for (int k = 0; k <= ones; ++k)
        {
            Mint A(0);
            for (int l = ones; l >= 0; --l)
            {
                A += dp[l][k];
                
                ndp[l][k] += A;
            }
        }

        dp.swap(ndp);
        
    }

    Mint ans;

    for (int d = 0; d <= min(ones, k); ++d)
    {
        ans += dp[0][d];
    }

    cout << ans << endl;

    return 0;
}


