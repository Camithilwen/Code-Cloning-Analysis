#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int k,t;
  cin >> k >> t;
  vector<int>a(t);
  rep(i,0,t) cin >> a[i];
  sort(a.begin(),a.end());
  if(a[t-1] <= (k+1)/2){
    cout << 0 << endl;
    return 0;
  }
  cout << (a[t-1]-(k+1)/2)*2-1 << endl;
}