#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool AC = true;
  if(s[0] != 'A') AC = false;
  int count = 0;
  for(int i=2; i<s.size()-1; i++) {
    if(s[i]=='C') count++;
    else if (isupper(s[i])) AC = false;
    if(i==s.size()-2 && count != 1) AC = false;  
  }
  for(int i=1; i<s.size(); i++) {
    if(i==1 || i==s.size()-1) {
      if(isupper(s[i])) AC = false;
    }
  }
  if(AC) cout << "AC" << endl;
  else cout << "WA" << endl;
  return 0;
 }