#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<bool> v(26, true);
  for(int i=0; i<s.size(); i++) v[s[i]-'a'] = false;
  
  char ans;
  for(int i=0; i<26; i++) {
    if(v[i]) {
      ans = i+'a';
      cout << ans << endl;
      break;
    }
    else if(i==25) cout << "None" << endl;
  }
  return 0;
}