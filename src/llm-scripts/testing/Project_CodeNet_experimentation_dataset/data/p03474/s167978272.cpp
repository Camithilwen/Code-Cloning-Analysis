#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;
  string s; cin >> s;
  
  bool ok = true;
  if(s.size()!=a+b+1) ok = false;
  
  a--;b--;
  rep(i,s.size()){
    if(i==a+1 && s[i]!='-') ok =false;
    if(i!=a+1 && s[i]-'0'<0 || s[i]-'0'>9) ok = false;
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
