#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  int mn = max(-1000000,b-a+1);
  int mx = min(1000000,b+a-1);
  cout << mn;
  for(int i = mn+1;i<mx+1;i++) cout << " " << i ;
}