#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main() {
  string input;
  cin >> input;
  regex pattern("^A[a-z]+C[a-z]+$");
  if (regex_match(input, pattern))
  {
    cout << "AC" << endl;
  }
  else
  {
    cout << "WA" << endl;
  }
  return 0;
}
