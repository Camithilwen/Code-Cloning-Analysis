#include<iostream>
main(){
  std::string s;
  std::cin>>s;
  int n=s.size();
  std::cout<<s.substr(0,n-8)<<std::endl;
}