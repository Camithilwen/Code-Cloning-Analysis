#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  cout << "2018/01/" << s.substr(s.size() - 2) << endl;
  return 0;
}
