#include <bits/stdc++.h>

using namespace std;

int main(){
  int k, t, a[109];
  cin >> k >> t;
  for(int i=0;i<t;i++)cin >> a[i];
  int ans=0;
  for(int i=0;i<t;i++){
    int rest=max(a[i]-(k+1)/2, 0);
    if(rest==1)ans++;
    else if(rest>1){
      ans += 1+2*(rest-1);
    }
  }
  cout << ans << endl;
}

