#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  if(s.size()%2 == 1){
    cout << "No" << endl;
    return 0;
  }
  rep(i,s.size()){
    if(i%2 == 0 && s[i] != 'h'){
      cout << "No" << endl;
      return 0;
    }
    if(i%2 == 1 && s[i] != 'i'){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}