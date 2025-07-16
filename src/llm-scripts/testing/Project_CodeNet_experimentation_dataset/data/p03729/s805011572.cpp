#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;
bool check(string x, string y) {
  int a = x.size()-1;
  return x[a] == y[0];
}

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if(check(a, b) && check(b, c)) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
