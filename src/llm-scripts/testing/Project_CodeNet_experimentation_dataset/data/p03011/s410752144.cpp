#include<iostream>

int main(void){
    int p, q, r;
    std::cin >> p >> q >> r;
    int ans;
    ans = std::min(p+q, p+r);
    ans = std::min(ans, q+r);
    std::cout << ans << std::endl;
    return 0;
}