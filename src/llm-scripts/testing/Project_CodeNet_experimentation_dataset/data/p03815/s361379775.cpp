#include <iostream>

int main()
{
    int64_t x;
    std::cin >> x;
    // 5と6を交互に出す
    // どちらから始めてもいいので、最後を6にできる
    const auto r = x % 11;
    std::cout << x / 11 * 2 + (r + 5) / 6 << std::endl;
    return 0;
}
