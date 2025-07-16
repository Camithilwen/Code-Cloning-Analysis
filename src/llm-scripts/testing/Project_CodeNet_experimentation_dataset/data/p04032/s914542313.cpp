#include <bits/stdc++.h>
using namespace std;
int main(){
  string s; cin >> s;
  int n = s.size();
  for(int i = 0; i < n; i++){
    if(i < n-1 && s[i] == s[i+1]){
      cout << i+1 << " " << i+2 << endl;
      return 0;
    }else if(i < n-2 && s[i] == s[i+2]){
      cout << i+1 << " " << i+3 << endl;
      return 0;
    }
  }
  cout << "-1 -1" << endl;
  return 0;
}