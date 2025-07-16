#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;

    std::cout << s.substr(0, s.length() - 8) << std::endl;
}
