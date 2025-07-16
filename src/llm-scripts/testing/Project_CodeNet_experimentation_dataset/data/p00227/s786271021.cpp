#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>
#include <algorithm>

int main(){

    int purchase_num;
    int max_cap;

    while(std::cin >> purchase_num >> max_cap){
        if(purchase_num == 0 && max_cap == 0) break;
        std::vector<int> price;
        std::string str;
        int input_data;
        int min_price = 0;
        std::cin.ignore();
        std::getline(std::cin, str);
        std::istringstream iss(str);
        while(!iss.eof()){
            iss >> input_data;
            price.push_back(input_data);
        }
        std::sort(price.begin(),price.end(),std::greater<int>());
        for(int i = 0; i < price.size(); ++i){
            if((i+1)%max_cap != 0){
                min_price += price[i];
            }
        }
        std::cout << min_price << std::endl;
    }
    return 0;
}