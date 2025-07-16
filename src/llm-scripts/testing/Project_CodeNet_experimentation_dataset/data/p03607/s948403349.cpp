#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;

  map<int, int> m;
  int x;
  rep (i, n){
    cin >> x;
    if (m[x] == 0) m[x] = 1;
    else m[x] = 0;
  }
  int count = 0;
  for (P p : m){
    if (p.second == 1) ++count;
  }
  cout << count << endl;
  return 0;
}