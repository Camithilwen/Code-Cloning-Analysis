#include <iostream>
int main()
{
  int n;
  std::cin >> n;
  std::string line;
  std::getline(std::cin, line);
  while (n--) {
    std::getline(std::cin, line);
    
    int i;
    while ((i = line.find("Hoshino")) != std::string::npos) {
      line.replace(i, 7, "Hoshina");
    }
    std::cout << line << std::endl;
  }
  return 0;
}