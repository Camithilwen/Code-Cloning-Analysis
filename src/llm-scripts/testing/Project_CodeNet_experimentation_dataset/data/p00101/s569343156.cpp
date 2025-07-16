#include <string>
#include <iostream>
using namespace std;

int main()
{
  string s;
  getline(cin, s);
  while (getline(cin, s)) {
    string::size_type b = 0, e;
    do {
      e = s.find("Hoshino", b);
      if (e != string::npos) {
	s[e+6] = 'a';
      }
      b = e + 1;
    } while (e != string::npos);
    cout << s << endl;
  }
  return 0;
}