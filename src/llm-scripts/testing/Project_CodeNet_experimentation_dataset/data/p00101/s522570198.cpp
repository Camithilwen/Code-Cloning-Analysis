#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int n;
  string s;
  string::size_type t;
  cin >> n;
  getchar();
  while (n--) {
    getline(cin, s);
    t = 0;
    while ((t = s.find("Hoshino", t)) != string::npos) {
      s[t + 6] = 'a';
      t += 1;
    }
    cout << s << endl;
  }
  return 0;
}