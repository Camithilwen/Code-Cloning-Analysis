#include <iostream>
#include <vector>
#include <algorithm>

int main (){
    int n = 0, m = 0;
    while(true){
        int ans = 0; //for answer
        std::cin >> n >> m;
        //exit when n = m = 0
        if(n == 0 && m == 0){
            break;
        }
        std::vector<int> price(n); //each vegetable price
        //put price to vector
        for(int i = 0; i < n; ++i){
            std::cin >> price[i];
        }
        //descending sort
        std::sort(price.begin(), price.end(), std::greater<int>());
        //m'th vegetable don't add
        for(int i = 0; i < n; ++i){
            if((i+1) % m != 0){
                ans += price[i];
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}