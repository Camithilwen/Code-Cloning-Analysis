#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int n = -1;
  for(int i = 0;i < s.size();i++){
    if(s.at(i)=='A'){
      n = i;
      break;
    }
  }
  
  int m = -1;
   for(int j = 0;j < s.size();j++){
    if(s.at(j)=='C'){
      m = j;
      if(n+1==m){
        break;
      }
    }
  }
  
  if(n >= 0 && m >= 0 && n+1==m){
    cout << "Yes" << endl;
  }
  
  else{
    cout << "No" << endl;
  }
}