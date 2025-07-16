#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  if(s.size() == 2) {
    cout << s << endl;
  }
  else if(s.size() == 3) {
    for(int i = 2; i > -1; i--) {
      cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
