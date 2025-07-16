#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
*/



int main() {
  string S;
  cin >> S;
  bool flag = false;
  for(int i = 0;i<S.size()-1;i++){
      if(S[i] == 'A' && S[i+1] == 'C'){
          flag = true;
          break;
      }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  }