#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

int main(){
    int n,m,x;
    
    while(std::cin >> n >> m){
        
        if(n == 0 && m == 0)
            break;
        
        int flag = 0;
        int num = 0;
        std::vector<int> v;
        std::string line;
    
        std::getline(std::cin, line);
    
        if(std::getline(std::cin, line)){
            std::istringstream ss(line);
            while(ss >> x){
                v.push_back(x);
            }
        }
        
        sort(v.rbegin(),v.rend());
    
        for(int y = 0;y < n;++y){
            ++flag;
            if(flag != m){
                num += v[y];
            }
            else
                flag = 0;
        }
        std::cout << num << std::endl;
    }
}
