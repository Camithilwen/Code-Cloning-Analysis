#include <iostream>
#include <string>
int main(){
  char s[10];
  for (int i = 0; i < 10; i++){
    std::cin >> s[i];
    if (i == 3){
      s[i] = '8';
    }
  }

  for (int i = 0; i < 10; i++){
    std::cout << s[i];
  }
  std::cout << std::endl;
  return 0;
}