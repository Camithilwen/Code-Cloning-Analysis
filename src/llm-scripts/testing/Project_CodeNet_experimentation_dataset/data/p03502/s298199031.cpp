#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int sum = 0;
  vector<int> v(s.size());
  for(int i=0; i<s.size(); i++) {
    v[i] = s[i]-'0';
    sum += v[i];
  }
  if(stoi(s)%sum==0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}