#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;cin >>s;
  
  if(s.size()%2)cout << "No" << endl;
  else{
    bool ok = true;
    
    for(int i=0; i<s.size(); i++){
      if(i%2==0 && s[i]!='h'){
        ok = false;
        break;
      }
      if(i%2==1 && s[i]!='i'){
        ok = false;
        break;
      }
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}