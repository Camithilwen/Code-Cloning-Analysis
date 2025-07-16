#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n,ans,W[310000] = {},E[310000] = {};
  string s;
  cin >> n >> s;
  
  for(int i = 1; i <= n-1; i++) {
    if(s[i-1] == 'W') 
      W[i] = W[i-1] + 1;
    else W[i] = W[i-1];
  }
  for(int i = n-2; i >= 0; i--) {
    if(s[i+1] == 'E') 
      E[i] = E[i+1] + 1;
    else E[i] = E[i+1];
  }

  int m = n;
  for(int i = 0; i < n; i++)
    m = min(m,W[i]+E[i]);
  
  cout << m << endl;
}