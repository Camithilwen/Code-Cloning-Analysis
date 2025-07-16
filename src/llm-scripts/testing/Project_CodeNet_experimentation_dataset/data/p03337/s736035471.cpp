#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c=0,d=0,e=0;
  cin >> a >> b;
  c += a+b;
  d += a-b;
  e += a*b;
  cout << max(c,max(d,e)) << endl;
}
