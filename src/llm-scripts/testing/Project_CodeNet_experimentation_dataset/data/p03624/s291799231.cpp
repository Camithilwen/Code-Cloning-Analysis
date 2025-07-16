#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s; cin >> s;
  string c = "abcdefghijklmnopqrstuvwxyz";
  bool find_flag = false;
  
  for (int i=0; i<26; i++) {
    bool target = false;
    for (int j=0; j<s.length(); j++) {
      if (c[i] == s[j]) target = true;
    }
    if (!target) {
      cout << c[i] << endl;
      find_flag = true;
      break;
    }
  }
  
  if (!find_flag) cout << "None" << endl;
  return 0;
}