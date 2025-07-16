#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  string a,b,c;
  cin >> a >> b >>c ;
  if(a.back() == b.front() && b.back() == c.front()) cout <<"YES" << endl;
  else cout << "NO" << endl;
}