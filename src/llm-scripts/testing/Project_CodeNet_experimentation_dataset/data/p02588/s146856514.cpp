#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> memo(60, std::vector<int> (25));
    for (int i = 0; i < n; ++i)
    {
        long double a;
        std::cin >> a;
        long long b = (long long) (a * 1e9 + 0.5);
        int count2 = 0, count5 = 0;
        while (b % 2 == 0)
        {
            ++count2;
            b /= 2;
        }
        while (b % 5 == 0)
        {
            ++count5;
            b /= 5;
        }
        ++memo[count2][count5];
    }
    long long ans = 0;
    for (int i = 0; i < 60; ++i)
    {
        for (int j = 0; j < 25; ++j)
        {
            for (int ii = std::max(0, 18 - i); ii < 60; ++ii)
            {
                for (int jj = std::max(0, 18 - j); jj < 25; ++jj)
                {
                    if (i != ii || j != jj)
                    {
                        ans += 1LL * memo[i][j] * memo[ii][jj];
                    }
                }
            }
        }
    }
    ans /= 2;
    for (int i = 0; i < 60; ++i)
    {
        for (int j = 0; j < 25; ++j)
        {
            if (i + i >= 18 && j + j >= 18)
            {
                ans += 1LL * memo[i][j] * (memo[i][j] - 1) / 2;
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}