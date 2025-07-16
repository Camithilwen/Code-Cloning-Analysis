#include <iostream>

int main () {
	std::string a, b, c;
      
  std::cin >> a >> b >> c;
 
  if(a.substr(a.size()-1, 1) == b.substr(0, 1) && b.substr(b.size()-1, 1) == c.substr(0, 1)) {
  	std::cout << "YES" << std::endl;
  }else {
  	std::cout << "NO" << std::endl;
  }
}