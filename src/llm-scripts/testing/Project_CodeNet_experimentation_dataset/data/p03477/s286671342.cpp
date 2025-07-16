#include <iostream>
#include <string>

int main () {
  int a, b, c, d;
  std::string ans = "";
  std::cin >> a >> b >> c >> d;
  int x = a + b - c - d;
  if(x > 0) ans = "Left";
  else if(x == 0) ans = "Balanced";
  else ans = "Right";
  std::cout << ans << std::endl;
}
