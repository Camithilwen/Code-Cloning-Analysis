#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  int a, b, l, x;
  char c;
  while (getline(cin, str)) {
    x = 0;
    l = (int)str.size();
    for (int i=0; i<l; i++) {
      c = str.at(i);
      if (c == 'I') a = 1;
      else if (c == 'V') a = 5;
      else if (c == 'X') a = 10;
      else if (c == 'L') a = 50;
      else if (c == 'C') a = 100;
      else if (c == 'D') a = 500;
      else if (c == 'M') a = 1000;
      if (i) {
        if (b >= a) {
          x += b;
        } else {
          x -= b;
        }
      }
      b = a;
    }
    x += b;
    cout << x << endl;
  }
  return 0;
}