#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,n){
    cin >> a[i];
  }
  int k=1000000;
  int ans=0;
  rep(i,n){
    k=min(k,a[i]);
    if(k==a[i]){
      ans++;
    }
  }
  cout << ans << endl;

  return 0;

}
