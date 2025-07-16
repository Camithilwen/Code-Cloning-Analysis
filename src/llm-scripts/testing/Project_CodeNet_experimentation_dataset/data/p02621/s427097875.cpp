#include <iostream>
#include <string>

int main() 
{
    unsigned int a = 0, max_num = 11, min_num = 0;

    std::cin >> a;
    if ((min_num < a) && (a < max_num)) {
        a = a + (a * a) + (a * a * a);
        std::cout << a;
    }
    else
    {
        std::cout << "Err a = " << a;
    }

}