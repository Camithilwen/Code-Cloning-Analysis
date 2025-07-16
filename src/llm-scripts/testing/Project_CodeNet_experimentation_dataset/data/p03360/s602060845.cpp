#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  vector<int> a(3);
  rep(i,3) cin >> a[i];
  int k; cin >> k;
  sort(a.begin(), a.end());
  for(int i = 0; i < k; i++){
    a[2] *= 2;
  }
  int ans = 0;
  rep(i,3) ans += a[i];
  cout << ans << endl;
  return 0;
}
