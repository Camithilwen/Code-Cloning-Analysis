#include <bits/stdc++.h>
#include <regex>
using namespace std;

#define _GLIBCXX_DEBUG

//vector<int> A(M), B(M);
//vector<vector<char>> answer(N, vector<char>(N, '-'));

int main() {
  string s;
  int ans = 0;
  
  cin >> s;
  
  if(s[0] == 'R'){
    ans++;
    if(s[1] == 'R'){
      ans++;
      if(s[2] == 'R') ans++;
    }
  }
  
  else{
    if(s[1] == 'R'){
      ans++;
      if(s[2] == 'R') ans++;
    }
    else{
      if(s[2] == 'R') ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}