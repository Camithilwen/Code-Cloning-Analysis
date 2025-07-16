#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  string s1 = "Hoshino", s2 = "Hoshina";
  string::size_type pos;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    for (pos = line.find(s1); pos != string::npos; pos = line.find(s1, s2.length() + pos))
      line.replace(pos, s1.length(), s2);
    cout << line << endl;
  }

  return 0;
}