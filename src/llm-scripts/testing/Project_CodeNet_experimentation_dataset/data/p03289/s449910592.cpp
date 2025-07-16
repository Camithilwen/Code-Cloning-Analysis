#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s;
  cin >> s;
  
  bool flag = true;
  int n = s.size();
  int ok = 0;
  if(s[0] != 'A'){
    cout << "WA" << endl;
    return 0;
  }
  
  for(int i = 2; i <= n-2; i++){
    if(s[i] == 'C'){
      ok++;
    }
  }
  if(ok != 1){
    cout << "WA" << endl;
    return 0;
  }
  
  for(int i = 0; i < n; i++){
    if(s[i] != 'A' && s[i] != 'C' && isupper(s[i])){
      cout << "WA" << endl;
      return 0;
    }
  }
  
  cout << "AC" << endl;
}