#include <iostream>

int main(){
    std::string inp;
    std::cin >> inp;
    for(char& c:inp)
        if (c == '7') {std::cout << "Yes"; return 0;}
    std::cout << "No";

    return 0;
}