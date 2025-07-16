#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  bool can = true;
  
  if(S.at(0)!='A') can = false;
  
  int num_C = 0;
  for(int i=2;i<S.size()-1;i++){
    if(S.at(i)=='C') num_C ++;
  }
  if(num_C!=1) can =false;

  int num_upper = 0;
  for(int i=0;i<S.size();i++){
    if(isupper(S.at(i))) num_upper ++;
  }
  if(num_upper!=2) can = false;
  
  if(can) cout << "AC" << endl;
  else cout << "WA" << endl;  
}