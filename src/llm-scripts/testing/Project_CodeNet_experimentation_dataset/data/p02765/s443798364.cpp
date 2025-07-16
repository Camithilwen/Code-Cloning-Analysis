#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    int N, R;
    std::cin >> N >> R;

    if(N >= 10) {
        std::cout << R << std::endl;
    }
    else {
        std::cout << R + (10-N)*100 << std::endl;
    }
}