#include <bits/stdc++.h>
using namespace std;

int main() {
  string A,B,C; cin >> A >> B >> C;
  int a,b,c;
  a = A.size();
  b = B.size();
  c = C.size();
  char s,t,u,v;
  s = A.at(a-1);
  t = B.at(0);
  u = B.at(b-1);
  v = C.at(0);
  if (s == t && v == u){
    cout << "YES";
  }
  else cout << "NO";
}