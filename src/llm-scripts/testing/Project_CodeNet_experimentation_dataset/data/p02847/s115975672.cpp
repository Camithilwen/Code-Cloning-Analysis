#include <iostream>
#include <string>

int main() {
std::string str;
std::cin >> str;
  if (str == "MON") {
    std::cout << 6;
  }
  if (str == "TUE") {
    std::cout << 5;
  }
  if (str == "WED") {
    std::cout << 4;
  }
  if (str == "THU") {
    std::cout << 3;
  }
  if (str == "FRI") {
    std::cout << 2;
  }
  if (str == "SAT") {
    std::cout << 1;
  }
  if (str == "SUN") {
    std::cout << 7;
  }
}