#include <iostream>

int main()
{
    std::string s; std::cin >> s;

    for (size_t i = 0; i < s.size() - 8; i++) {
        std::cout << s[i];
    }
    std::cout << std::endl;
    return 0;
}
