#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  string s;
  vector<vector<char>> v(h+2, vector<char>(w+2));
  for(int i=0; i<h+2; i++) {
    if(i==0 || i==h+1) for(int j=0; j<w+2; j++) v[i][j] = '.';
    else {
      cin >> s;
      for(int j=0; j<w+2; j++) {
        if(j==0 || j==w+1) v[i][j] = '.';
        else v[i][j] = s[j-1];
      }
    }
  }
  
  bool check = true;
  for(int i=0; i<h+2; i++) {
    for(int j=0; j<w+2; j++) {
      if(v[i][j]=='#') {
        if(v[i-1][j]!='#' && v[i+1][j]!='#' && v[i][j-1]!='#' && v[i][j+1]!='#') check = false;
      }
    }
  }

  if(check) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}