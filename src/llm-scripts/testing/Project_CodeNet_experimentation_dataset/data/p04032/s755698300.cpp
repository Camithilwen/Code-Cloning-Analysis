#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  string s; cin >> s;
  int n = s.size();
  for(int i = 0; i < n - 1; i++){
    if(s[i] == s[i + 1]){
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
    if(i < n - 2 && s[i] == s[i + 2]){
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
}