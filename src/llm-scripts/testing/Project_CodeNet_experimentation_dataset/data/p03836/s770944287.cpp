#include <iostream>

int main()
{
    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    for (int i = 0; i < ty - sy; ++i)
    {
        std::cout << 'U';
    }
    for (int i = 0; i < tx - sx; ++i)
    {
        std::cout << 'R';
    }
    // tに到達した

    for (int i = 0; i < ty - sy; ++i)
    {
        std::cout << 'D';
    }
    for (int i = 0; i < tx - sx; ++i)
    {
        std::cout << 'L';
    }
    // sに戻った

    std::cout << 'L';
    for (int i = 0; i < ty - sy + 1; ++i)
    {
        std::cout << 'U';
    }
    for (int i = 0; i < tx - sx + 1; ++i)
    {
        std::cout << 'R';
    }
    std::cout << 'D';
    // 2回目のt

    std::cout << 'R';
    for (int i = 0; i < ty - sy + 1; ++i)
    {
        std::cout << 'D';
    }
    for (int i = 0; i < tx - sx + 1; ++i)
    {
        std::cout << 'L';
    }
    std::cout << 'U';

    std::cout << std::endl;
    return 0;
}
