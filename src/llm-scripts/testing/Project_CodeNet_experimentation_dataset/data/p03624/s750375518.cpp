#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  
  bool ok = false;
  char c;
  
 for (c = 'a' ; c <= 'z'; c++ ) {
   ok = false;
  for (int i = 0; i < S.size(); i++) {
    if(S.at(i) == c){
      ok = true;
      break;
    }
  }
    if(ok == false){
    break;
    }
 }
  
  if(ok == false){
  	cout << c << endl;
  }else {
    cout << "None" << endl;
  }

}