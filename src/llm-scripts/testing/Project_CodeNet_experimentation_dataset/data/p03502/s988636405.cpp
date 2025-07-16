#include <bits/stdc++.h>
using namespace std;

int main() { 
  string s;
  cin >> s;
  int c = s.size();
  int p = 0;
  int q = 0;

  for (int i = 0; i < c; i++){
    p *= 10;
    p += s.at(i) - '0';

    q += s.at(i) - '0';
  } 
  if(p%q==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
