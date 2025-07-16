#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int a,b,c;
  cin >>a >>b >>c;
  int M = max(a,b);
  int m = min(a,b);
  if(M>=c && m<=c) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}