#include <iostream>
#include <string>

int main() 
{
    int A, B, C;
    std::cin >> A; std::cin >> B; std::cin >> C;
    std::cout << std::to_string(C) + " " + std::to_string(A) + " " + std::to_string(B) << std::endl;
}