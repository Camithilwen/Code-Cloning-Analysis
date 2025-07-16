#include<iostream>
int H,W,A,B;
int main(){
    std::cin>>H>>W>>A>>B;
    for(int i=0;i<H*W;i++)std::cout<<(i%W<A^i/W<B)<<(i%W==W-1?"\n":"");
    return 0;
}