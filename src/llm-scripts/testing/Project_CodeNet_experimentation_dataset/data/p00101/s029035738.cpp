#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    for (int i = 6; i < s.length(); i++)
      if (s[i-6] == 'H' &&
          s[i-5] == 'o' &&
          s[i-4] == 's' &&
          s[i-3] == 'h' &&
          s[i-2] == 'i' &&
          s[i-1] == 'n' &&
          s[i] == 'o')
        s[i] = 'a';
    cout << s << endl;
  }
  return 0;
}