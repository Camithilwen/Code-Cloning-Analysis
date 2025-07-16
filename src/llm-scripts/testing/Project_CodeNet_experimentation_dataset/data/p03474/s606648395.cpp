#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int A,B;
  cin >> A >> B;
  string S;
  cin >> S;
  for(int i=0;i<(int)S.size();i++){
    if(i==A){
      if(S[i]!='-'){
        cout << "No" << endl;
        return 0;
      }
    }
    else{
      if(!(S[i]-'0'>=0 && S[i]-'0'<=9)){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}