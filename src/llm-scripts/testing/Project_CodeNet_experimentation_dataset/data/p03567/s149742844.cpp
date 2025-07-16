#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool flg = false;
  for(int i = 0; i < s.size(); i++){
    if(flg){
      if(s[i] == 'C'){
        cout << "Yes" << endl;
        return 0;
      }else{
        flg =false;
      }
    }else{
      if(s[i] == 'A') flg = true;
    }
  }
  cout << "No" << endl;
  return 0;
}