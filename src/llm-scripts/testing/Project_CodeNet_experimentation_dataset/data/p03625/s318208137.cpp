#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int main() {
  int N; cin >>N;
  vector<ll> check;
  rep(i,0,N) {
    ll A; cin >>A;
    check.push_back(A);
  }
  sort(check.rbegin(),check.rend());
  ll temp=0;
  rep(i,1,N) {
    if (check[i-1]==check[i]) {
      if (!temp) {
        temp=check[i];
        i++;
      } else {
        cout <<check[i]*temp <<endl;
        return 0;
      }
    }
  }
  cout <<0 <<endl;
  return 0;
}
