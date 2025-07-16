#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  cin >> A.at(0);
  ll ans = 0;
  rep(i,N-1){
    cin >> A.at(i+1);
    if(A.at(i+1) < A.at(i)){
      ans += A.at(i) - A.at(i+1);
      A.at(i+1) = A.at(i);
    }
  }
  cout << ans << endl;
  return 0;
}