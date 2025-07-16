#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)

int main() {
  int n, q;
  cin >> n >> q;
  vector<tuple<int, int, int>> t;
  rep(i, n) {
    int l, r, x;
    cin >> l >> r >> x;
    l -= x;
    r -= x;
    t.push_back(make_tuple(l, 1, x));
    t.push_back(make_tuple(r, 0, x));
  }
  rep(i, q) {
    int d;
    cin >> d;
    t.push_back(make_tuple(d, 2, 0));
  }
  sort(all(t));
  set<int> st;
  for(auto v : t) {
    int l, b, x;
    tie(l, b, x) = v;
    if(b == 2)
      cout << (st.empty() ? -1 : *st.begin()) << endl;
    else if(b == 1)
      st.insert(x);
    else
      st.erase(x);
  }
}
