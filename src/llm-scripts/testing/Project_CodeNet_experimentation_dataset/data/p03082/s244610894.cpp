#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int MOD = 1e9 + 7;

template<class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template<class T, class V>
typename enable_if<is_class<T>::value == 0>::type fill(T &t, const V &v) {
    t = v;
}
template<class T, class V>
typename enable_if<is_class<T>::value != 0>::type fill(T &t, const V &v){
    for (auto &e : t) fill(e, v);
}
// auto v = make_vec<int>(h, w);
// fill(v, 0);

signed main(){

  int n, x; cin >> n >> x;
  vector<int> s(n);
  for(int i = 0; i < n; i++) cin >> s[i];
  sort(s.begin(),s.end());

  auto dp = make_vec<int>(n+1, x+1);
  for(int i = 0; i <= x; i++){
    dp[0][i] = i;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= x; j++){
      dp[i+1][j] += dp[i][j % s[i]]; dp[i+1][j] %= MOD;
      dp[i+1][j] += dp[i][j] * i; dp[i+1][j] %= MOD;
    }
  }
  cout << dp[n][x] << endl;

  return 0;
}
