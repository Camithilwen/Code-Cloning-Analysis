#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;


int main(){
  string S;
  cin >> S;
  ll ans = 0;
  int N = S.size();
  bool flag = false;
  REPR(i, N-1){
    int d = S[i] - '0';
    if(flag) d++;
    flag = false;
    if(d < 5){
      ans += d;
    }
    else if(d > 5){
      ans += 10 - d;
      flag = true;
    }
    else{
      if(i != 0 && S[i-1] >= '5'){
        ans += d;
        flag = true;
      }
      else{
        ans += d;
      }
    }
  }
  if(flag) ans++;
  cout << ans << endl;
  return 0;
}