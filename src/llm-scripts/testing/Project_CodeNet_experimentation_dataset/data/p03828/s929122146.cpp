#include <iostream>
#include <unordered_map>
#include <cmath>

void FactrizePrime(int x, std::unordered_map<int, int> &count)
{
    while (x % 2 == 0)
    {
        ++count[2];
        x /= 2;
    }
    for (int i = 3; i <= x; i += 2)
    {
        while (x % i == 0)
        {
            ++count[i];
            x /= i;
        }
    }
}

constexpr int32_t MOD = 1000000007;

int main()
{
    int n;
    std::cin >> n;
    if (n == 1 || n == 2)
    {
        std::cout << n << std::endl;
        return 0;
    }

    std::unordered_map<int, int> factor;
    for (int i = 2; i <= n; ++i)
    {
        FactrizePrime(i, factor);
    }

    int64_t count = 1;
    for (const auto &p : factor)
    {
        count *= p.second + 1;
        count %= MOD;
    }

    std::cout << count << std::endl;
    return 0;
}
