#include <bits/stdc++.h>


int main() {
    unsigned int firstNumber;
    unsigned int lastNumber;
    std::cin >> firstNumber >> lastNumber;
    
    unsigned int numOfPalindrome = 0U;
    for(unsigned int i = firstNumber; i <= lastNumber; ++i) {
        std::string forwardNumber = std::to_string(i);
        std::string reverseNumber = forwardNumber;
        std::reverse(reverseNumber.begin(), reverseNumber.end());
        
        if(forwardNumber == reverseNumber) {
            ++numOfPalindrome;
        }
    }
    std::cout << numOfPalindrome << std::endl;
}