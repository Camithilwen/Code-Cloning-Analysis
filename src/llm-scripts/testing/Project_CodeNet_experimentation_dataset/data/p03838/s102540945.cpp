#include<iostream>

int main(){
    long long a,b;
    std::cin >> a >> b;
    long long ans = 1e18;
    if(std::abs(a) == std::abs(b)){
       std::cout << 1 << std::endl;
       return 0;
    }
    if(-a < b){
      ans = std::min(ans, a + b + 1);
    }
    if(a < -b){
       ans = std::min(-a - b + 1, ans);
    }
    if(-a < -b){
        ans = std::min(ans,a - b + 2);
    }
    if(a < b){
        ans = std::min(ans, b - a);
    }
    std::cout << ans << std::endl;
}