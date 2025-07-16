#include <iostream>
using namespace std;

bool check(string S){
  if(S[0]!='A') return false;
  int C=0;
  for (int i = 2 ; i < S.length()-1; i++) {
    if(S[i]=='C'){
      C++;
    }
  }
  if(C!=1) return false;
  int upper=0;
  for (int i = 0; i < S.length(); i++) {
    if(S[i]>='A'&&S[i]<='Z'){
      upper++;
    }
  }
  if(upper!=2) return false;
  return true;
}

int main(){
  string S;
  cin >> S;
  if(check(S)){
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
}
