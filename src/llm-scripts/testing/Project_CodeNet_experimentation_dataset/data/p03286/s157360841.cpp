#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
int main(){
    int N;
    std::vector<int> vec;



    std::cin>>N;
    
    if(N==0){
        std::cout<<0<<std::endl;
        return 0;
    }
    
    while(N!=0){
        vec.emplace_back(abs(N%2));
        N-=abs(N%2);
        N/=-2;
    }

    
    for(int i=vec.size()-1;0<=i;i--) std::cout<<vec[i];
    std::cout<<std::endl;

    return 0;
}