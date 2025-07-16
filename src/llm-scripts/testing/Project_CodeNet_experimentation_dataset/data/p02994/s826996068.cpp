#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, l;
  cin >> n >> l;
  int ans = 0;
  for(int i=l; i<l+n; ++i){
    if(l+n-1 < 0 && i == l+n-1) continue;
    if(l > 0 && i == l) continue;
    ans += i;
  }
  cout << ans << endl;
}