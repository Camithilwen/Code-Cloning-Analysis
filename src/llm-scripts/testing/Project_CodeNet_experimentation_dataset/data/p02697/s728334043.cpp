#include<iostream>
int main(){
    int N,M;
    std::cin>>N>>M;
    int a,b;
    if(M%2==0){
        a=M/2;
        b=M/2;
    }else{
        a=M/2;
        b=M-a;
    }
    for(int i=1;i<=a;++i){
        std::cout<<i<<" "<<2*a+2-i<<std::endl;
    }
    for(int i=1;i<=b;++i){
        std::cout<<i+2*a+1<<" "<<M*2+2-i<<std::endl;
    }
}