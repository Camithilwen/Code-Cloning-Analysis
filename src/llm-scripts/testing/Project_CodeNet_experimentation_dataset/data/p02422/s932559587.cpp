#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

int main(void) {
    std::string str;
    int a;
    int b;
    int q;
    std::string start = "";
    std::string sub = "";
    std::string end = "";
    std::string s = "";
    std::cin >> str >> q;

    for (int i = 0; i < q; i++) {
        std::string order;
        std::cin >> order;
        std::cin >> a >> b;
        start = str.substr(0, a);
        sub = str.substr(a, b - a + 1);
        end = str.substr(b + 1, str.size() - b);

        if (order == "replace") {
            s = "";
            std::cin >> s;
            str = start + s + end;
        } else if (order == "reverse") {
            std::reverse(sub.begin(), sub.end());
            str = start + sub + end;
        } else if (order == "print") {
            std::cout << sub << std::endl; 
        } else {
        }
    }

    return EXIT_SUCCESS;
}