#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  bool a=false;
  for(int i=0;i<S.size()-1;i++){
    if(S.at(i)=='A' && S.at(i+1)=='C'){
      cout << "Yes" << endl;
      a=true;
      break;
    }
  }
  if(!a){
    cout << "No" << endl;
  }
}