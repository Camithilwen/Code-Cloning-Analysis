#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    std::string s; std::cin >> s;
    int A = s[0] - '0';
    int B = s[1] - '0';
    int C = s[2] - '0';
    int D = s[3] - '0';
    if (A + B + C + D == 7)
        std::cout << A << "+" << B << "+" << C << "+" << D << "=7" << std::endl;
    else if(A + B + C - D == 7)
        std::cout << A << "+" << B << "+" << C << "-" << D << "=7" << std::endl;
    else if (A + B - C + D == 7)
        std::cout << A << "+" << B << "-" << C << "+" << D << "=7" << std::endl;
    else if (A - B + C + D == 7)
        std::cout << A << "-" << B << "+" << C << "+" << D << "=7" << std::endl;
    else if (A - B + C - D == 7)
        std::cout << A << "-" << B << "+" << C << "-" << D << "=7" << std::endl;
    else if (A - B - C + D == 7)
        std::cout << A << "-" << B << "-" << C << "+" << D << "=7" << std::endl;
    else if (A + B - C - D == 7)
        std::cout << A << "+" << B << "-" << C << "-" << D << "=7" << std::endl;
    else if (A - B - C - D == 7)
        std::cout << A << "-" << B << "-" << C << "-" << D << "=7" << std::endl;

    return 0;
}