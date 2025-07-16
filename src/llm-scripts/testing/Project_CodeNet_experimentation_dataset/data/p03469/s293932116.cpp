#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;


int main() {
  string s;
  cin >> s;
  cout << 2018;
  rep(i, s.size()-4){
    cout << s[i+4];
  }
}