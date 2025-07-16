#include<iostream>
int main(){
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    if(A+B > C+D) std::cout<<"Left";
    else if(A+B < C+D) std::cout<<"Right";
    else std::cout<<"Balanced";
}