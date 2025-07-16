#include<bits/stdc++.h>
using namespace std;

int main(){
  int p, q, r; cin >> p >> q >> r;
  
  int m = max(p, max(q, r));
  int ans = p + q + r - m;
  cout << ans << endl;
}
