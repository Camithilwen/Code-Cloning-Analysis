#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  string s;
  int w;
  cin>>s>>w;
  for(int i(0);i<int(s.size());i++){
    if(i%w==0) cout << s[i];
  }
  cout << endl;
  return 0;
}

