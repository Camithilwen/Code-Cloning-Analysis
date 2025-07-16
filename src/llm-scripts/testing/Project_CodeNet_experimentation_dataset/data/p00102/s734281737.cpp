#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <iomanip>

int main(int argc, char* argv[])
{
    while (true) {
        std::string line;
        std::stringstream buffer;
        getline(std::cin, line);
        buffer << line;
        size_t length = 0;
        buffer >> length;
        if (length == 0) break;
        int *total = new int[length + 1];
        size_t width = length + 1;
        memset(total, 0, sizeof(int) * width);
        for (size_t i = 0; i < length; ++i) {
            getline(std::cin, line);
            std::istringstream s(line);
            std::string element;
            int sum = 0;
            for (size_t n = 0; n < length; ++n) {
               getline(s, element, ' ');
               std::stringstream tmp;
                int val = 0;
                tmp << element;
                tmp >> val;
                sum += val;
                total[n] += val;
                std::cout << std::setw(5) << val;
            }
            std::cout << std::setw(5) << sum << std::endl;
            total[length] += sum;
        }
        for (size_t i = 0; i < width; ++i) {
            std::cout << std::setw(5) << total[i];
        }
        std::cout << std::endl;
        delete[] total;
    }
    return 0;
}