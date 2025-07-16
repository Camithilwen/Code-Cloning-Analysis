#include <bits/stdc++.h>
using namespace std;
 // cout << (char)(z + 1);

int main(){
  string S;
  int frag;
  cin >> S;
  for (char c = 'a'; c != '{'; c = (char)(c + 1)){
    frag = 0;
    for (int i = 0; i < S.size(); i++){
      if(S.at(i) == c){
        frag = 1;
      }
    }
    if(frag == 0){
      cout << c << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}