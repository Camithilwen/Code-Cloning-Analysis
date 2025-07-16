#include <iostream> 
#include <string> 

int main(){
  std::string sent;
  int gyou,num=0;
  std::cin >> gyou;
  getline(std::cin, sent);
  for(int i=0;i<gyou;++i){
    num=0;
    getline(std::cin, sent);
    std::string bef="Hoshino",aft="Hoshina";
    while(num!=-1){
      num=(int)(sent.find(bef));
      if(num!=-1){
      sent.replace(num,bef.size(),aft);
      }
    }
    std::cout << sent << std::endl;
    /*if(i<gyou-1)
    std::cout << std::endl;*/
  }
  return 0; 
}