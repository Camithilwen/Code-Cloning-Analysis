#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  bool flag = true;
  if(a[a.size()-1] != b[0]) flag = false;
  if(b[b.size()-1] != c[0]) flag = false;
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}