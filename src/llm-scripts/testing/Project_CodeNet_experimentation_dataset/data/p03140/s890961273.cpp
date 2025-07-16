#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,ans=0;
  string a,b,c;
  cin >> n;
  cin >> a >> b >> c;
  for (int i = 0; i < n; i++){
    if (a[i] == b[i]){
      if (b[i] != c[i]){
        ans++;
      }
    }else if (b[i] == c[i]){
      ans++;
    }else if (a[i] == c[i]){
      ans++;
    }else{
      ans += 2;
    }
  }
  cout << ans << "\n";
}
