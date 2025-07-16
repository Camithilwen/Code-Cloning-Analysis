#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int a,b,num = 0;
  cin >> a >> b;
  
  for(int i = 0; a <= b; i++) {
    bool flag = 0;
    string s = to_string(a);
    int n = s.size();
    for(int j = 0; j < double(n/2); j++) {
      if(s[j] == s[n-1-j]) 
        flag = 1;
      else {
        flag = 0; 
        break;
      }
    }
    if(flag) num++;
    a++;
  }
  cout << num << endl;
}