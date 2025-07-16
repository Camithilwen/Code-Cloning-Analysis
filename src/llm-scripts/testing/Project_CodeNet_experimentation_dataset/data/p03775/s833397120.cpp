#include <iostream>
#include <cmath>

int main()
{
    int64_t n;
    std::cin >> n;

    for (int64_t a = std::floor(std::sqrt(n)); a >= 1; --a)
    {
        if (n % a == 0)
        {
            const int64_t b = n / a;
            std::cout << static_cast<int>(std::floor(std::log10(b) + 1)) << std::endl;
            break;
        }
    }
    return 0;
}
