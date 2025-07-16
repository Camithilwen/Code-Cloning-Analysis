#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n; cin >>n;
  string s,t;
  cin >>s >>t;
  for(int i = n; 0<=i; i--){
    if(s.substr(n-i)==t.substr(0,i)) {
      cout << 2*n-i << endl;
      return 0;
    }
  }
  return 0; 
}