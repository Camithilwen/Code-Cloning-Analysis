#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,m;
  string s[200],t[200];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> s[i];
  cin >> m;
  for(int i = 0; i < m; i++)
    cin >> t[i];

  int sum = 0;
  for(int i = 0; i < n; i++) {
    int cnt = 1;
    for(int j = i+1; j < n; j++)
      if(s[i] == s[j]) cnt++;
    for(int j = 0; j < m; j++)
      if(s[i] == t[j]) cnt--;
    sum = max(sum, cnt);
  }

  cout << sum << endl;
}