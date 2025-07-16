#include <iostream>
#include <string>
#include <map>

int main(){
    std::string s;
    std::cin >> s;

    std::map<std::string, int> day = {
        {"SUN", 0},
        {"MON", 1},
        {"TUE", 2},
        {"WED", 3},
        {"THU", 4},
        {"FRI", 5},
        {"SAT", 6}
    };

    std::cout << 7 - day[s] << std::endl;

    return 0;
}