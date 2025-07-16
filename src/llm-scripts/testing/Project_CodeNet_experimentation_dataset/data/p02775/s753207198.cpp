#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  string S;
  cin >> S;
  int N = S.size();
  int ans = 0;;
  int c = 0;
  REPR(i, N-1){
    int x = S[i] - '0';
    if((x+c) > 5){
      ans += 10 - (x+c);
      c = 1;
    }
    else if((x+c) == 5){
      if(i > 0 && S[i-1] >= '5'){
        ans += 10 -(x+c);
        c= 1;
      }
      else{
        ans += (x+c);
        c = 0;
      }
    }
    else{
      ans+= x+c;
      c = 0;
    }
  }
  ans += c;
  cout << ans << endl;
  return 0;
}
