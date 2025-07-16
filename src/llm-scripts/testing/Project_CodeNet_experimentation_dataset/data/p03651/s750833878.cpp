#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int gcd(int a, int b) {
  if (a % b == 0) {
    return(b);
  } else {
    return(gcd(b, a % b));
  }
}
int main() {
  ll N, K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll g = A[0]; ll max_n = *max_element(all(A));
  for(int i = 1; i < N; ++i) {
    g = gcd(A[i], g);
  }
  if(K % g == 0 && max_n >= K) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
