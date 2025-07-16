#include <cstring>
#include <iostream>
#include <string>
using namespace std;
void caesar(string &s, int n) {
  int i;
  char c;
  for (i = 0; c = s[i]; i++) {
    if (c >= 'a' && c <= 'z') 
      s[i] = 'a' + (c - 'a' + n) % 26;
  }
}
int main() {
  int n;
  string s;
  while (getline(cin, s)) {
    for (n = 0; n < 26; n++) {
      caesar(s, 1);
      if (s.find("the") != string::npos || s.find("this") != string::npos || s.find("that") != string::npos) {
        cout << s << endl;
        break;
      }
    }
  }
  return 0;
}