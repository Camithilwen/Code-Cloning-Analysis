#include <iostream>
#include <string>
int main(){
  std::string s;
  int n;
  std::cin>>n,std::cin.get();
  for(;n;n--){
    getline(std::cin,s);
    int pos=0;
    while(pos=s.find("Hoshino",pos),pos!=std::string::npos){
      s.replace(pos,7,"Hoshina");
      pos+=7;
    }
    std::cout<<s<<std::endl;
  }
  return 0;
}