#include<iostream>

const static int MIN = -1000000;
const static int MAX = 1000000;

int main(void){
    int k, x;
    std::cin >> k >> x;
    int cmax = std::min(MAX, x + k - 1);
    int cmin = std::max(MIN, x - k + 1);
    for(int i = cmin; i <= cmax; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}