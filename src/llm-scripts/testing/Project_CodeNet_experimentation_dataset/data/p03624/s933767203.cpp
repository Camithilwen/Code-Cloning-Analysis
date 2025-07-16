#include <iostream>
#include <map>

int main(void){
    char ans='0';
    std::string S;
    std::cin >> S;
    std::map<char, int> mp;
    for (int i=0; i<26; ++i){
        mp[(char)('a' + i)] = 0;
    }

    for (char c: S) ++mp[c];

    for (int i=0; i<26; ++i){
        if (mp[(char)('a' + i)] == 0){
            ans = (char)('a' + i);
            break;
        }
    }

    if (ans == '0') {
        std::cout << "None" << std::endl;
    } else {
        std::cout << ans << std::endl;
    }

    return 0;
}
