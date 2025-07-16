#include<iostream>
main(){
long a,b=-1,n,r;
std::cin>>n;
while(n--){
std::cin>>a;
if(a>b+1)return std::cout<<-1,0;
r+=a>b?1:a,b=a;
}
std::cout<<--r;
}
