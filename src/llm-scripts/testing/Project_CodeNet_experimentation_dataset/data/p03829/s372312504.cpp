#include <iostream>
#include <algorithm>

int main()
{
    int n;
    int64_t a, b;
    std::cin >> n >> a >> b;
    int x;
    std::cin >> x;

    int64_t sum = 0;
    for (int i = 1; i < n; ++i)
    {
        int y;
        std::cin >> y;
        sum += std::min((y - x) * a, b);

        x = y;
    }

    std::cout << sum << std::endl;
    return 0;
}
