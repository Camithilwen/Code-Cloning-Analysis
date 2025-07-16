#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<int> X(3);
  rep(i,3) cin >> X.at(i);
  
  swap(X.at(0), X.at(1));
  swap(X.at(0), X.at(2));
  
  for(auto e:X) cout << e << " ";
  cout << endl;
  return 0;
}


