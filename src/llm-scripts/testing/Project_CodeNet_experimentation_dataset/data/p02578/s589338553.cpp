#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  int n;
  cin >> n;
  vector<ll>a(n);
  ll sum=0;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n-1;++i) {
    if(a[i]>a[i+1]){
      sum+=a[i]-a[i+1];
      a[i+1]=a[i];
    }
  }
  cout << sum << endl;
  return 0;
}
