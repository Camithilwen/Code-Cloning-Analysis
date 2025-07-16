#include <iostream>
#include <string>
using namespace std;

int main() {
  int a;
  cin >> a;
  if(a < 1200) cout << "ABC\n";
  else if(a < 2800) cout << "ARC\n";
  else cout << "AGC\n";
}
