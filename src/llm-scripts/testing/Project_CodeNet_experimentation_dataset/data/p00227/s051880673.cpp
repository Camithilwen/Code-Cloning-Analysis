
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m, p, sum;

    while(std::cin >> n >> m){
        std::vector<int> price_list = {};

        if(n == 0 && m == 0){
            break;
        } else{
            sum = 0;
            for(int i = 0;i < n;++i){
                std::cin >> p;
                price_list.push_back(p);
                sum += p;
            }
            std::sort(price_list.begin(), price_list.end(), std::greater<int>());
            for(int i = 1;i <= n/m;++i){
                sum -= price_list.at(i * m - 1);
            }
            std::cout << sum << std::endl;
        }   
    }
    return 0;
}
