#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  string S;

  cin >> A >> B >> S;
  for(int i=0;i<S.size();++i){
    if(i == A){
      if(S.at(i) == '-'){
        continue;
      }else{
        cout << "No" << endl;
        return 0;
      }
    }else{
      if(S.at(i) == '-'){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
