#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  string s ;
  cin >> s ;
  int n ;
  cin >> n ;
  
  double t=s.size();
  string a ;
  
  for(int i=0 ; i<(t/n) ; i++ ){
    a+=s.at(0+i*n);
  }
  
  cout << a << endl;
}