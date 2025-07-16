#include <bits/stdc++.h>

using namespace std;

inline char shift(char c, int i) {
  return char(((c + i) - 'a') % 26 + 'a');
}

int main() {
  string str;
  while (getline(cin, str)) {
    int n;
    for (int i = 0; i < 26; ++i) {
      string target;
      for (char c : str) {
        if ('a' <= c && c <= 'z')
          target += shift(c, i);
        else
          target += c;
      }
      for (string key : {"the", "this", "that"}) {
        size_t pos = target.find(key);
        if (pos != string::npos) {
          n = i;
          str = target;
          goto found;
        }
      }
    }

found:
    cout << str << endl;
  }
}