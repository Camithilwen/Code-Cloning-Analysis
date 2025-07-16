#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n;
  cin >> n;
  multiset<ll> st;
  rep(i, n) {
    ll a;
    cin >> a;
    st.insert(a);
  }
  ll ans = 0;
  ll p2 = pow(2, 34);
  while(!st.empty()) {
    auto it = st.end();
    it--;
    ll p = p2;
    while(p > *it) {
      p /= 2;
      auto jt = st.lower_bound(p - *it);
      if(jt == it || jt == st.end() || *jt != p - *it) continue;
      st.erase(jt);
      ans++;
      break;
    }
    st.erase(it);
  }
  cout << ans << endl;
}