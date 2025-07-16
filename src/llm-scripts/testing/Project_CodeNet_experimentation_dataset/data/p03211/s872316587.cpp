#include<iostream>

int main(){
    std::string s; std::cin >> s;
    int diff=1e4;
    for(int i=0; i<s.size()-2; ++i){
        int num=std::stoi(s.substr(i,3));
        num = std::abs(num-753);
        diff = std::min(diff,num);
    }
    std::cout << diff << std::endl;
    return 0;
}